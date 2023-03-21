%% Definition der Variablen und Konstanten
clear
C = 343.2;                              %Schallgeschwindikeit in m/s
SystemDelayTime = 2;                    %Systemlaufzeit in ms
Abtastfrequenz=48000;                   %in Hz
Abtastintervall=1/Abtastfrequenz;

% Symbolische Variablen werden fuer die matlab solver function benoetigt und
% deshalb hier verwendet.

numSpeaker = 7;                         %Anzahl der Lautsprecher (Standart Variante ist bei 7)
numMicros = 9;                          %Anzahl der Mikrofone
numUnknownMicros = 6;                   %Anzahl der Unbekannten Mikrofone
t = zeros(numSpeaker, numMicros);       %Matrix für gesamte Laufzeit
Sample = zeros(numSpeaker, numMicros);  %Matrix für die Samples

overallUnknown = 3 *(numUnknownMicros + numSpeaker) + 1;    %Anzahl aller Unbekannten

TargetFunction = sym(zeros(numMicros * numSpeaker, 1));     %Matrix der Zielfunktion

%% Schleife

iterations = 20;

for run = 1:iterations
    
    randomNumber = 1 + 2 * rand;    %Zufallszahl fuer Abweichung von exakten Positionen    

    %% Hier sind die exakten Positionen
    MicrosPosition =   [30  0	0;  %Referenzmikrofon
                        0   20	0;  %Referenzmikrofon
                        0   0	0;  %Referenzmikrofon
                        -30 0	0;
                        0   -20	0;
                        15  17.32050808 0;
                        -15 17.32050808 0;
                        -15 -17.32050808 0;
                        15  -17.32050808 0];

    MPT = transpose(MicrosPosition);                        %Mikrofonposition wird transponiert
    rMPT = MPT(:) + randomNumber;                           %Transponierte Mikrofonpositionen werden mit Zufallszahlen versehen
    numKnownMicros =(numMicros-numUnknownMicros) * 3 + 1;   % Anzahl bekannter Mikrokoordinaten + Systemlaufzeit
    vrUMPT = rMPT(numKnownMicros:end);                      % vrUMPT = vectorized randomized UnknownMicrosPositionTransposed

    %Matrix der Lautsprecherpositionen mit einer Zufallshöhe
    SpeakersPosition = [-10     10      10;
                        10      10      8;
                        -10     -10     6;
                        10      -10     4;
                        0       0       2; 
                        -20     -5      1;
                        20      5       0];
                    %-20+40*rand -30+60*rand 15*rand
                    
%     %Matrix der Lautsprecherpositionen mit einer gemeinsamen Höhe
%      SpeakersPosition = [-10	10      0;
%                          10     10      0;
%                          -10    -10     0;
%                          10     -10     0;
%                          0      0       0; 
%                          -20    -5      0;
%                          20     5       0];

    SPT = transpose(SpeakersPosition); % SPT = SpeakersPositionTransposed
    rSPT = SPT(:) + randomNumber;      % rSPT = randomized SpeakersPositionTransposed
    vrSPT = rSPT(1:3*numSpeaker);      % vrSPT = vectorized randomized SpeakersPositionTransposed

    %% Unbekannten Vektor wird hier definiert, genauso wie die Distanzmatrix

    unknownVector = sym('U', [1 overallUnknown]);
    % unknownSpeaker = zeros(1, overallUnknown); waere zwar theoretisch das gleiche wird
    % aber von der Funktion nicht als eingabe akzeptiert

    DistanceMatrix = pdist2(SpeakersPosition, MicrosPosition, 'euclidean'); %Distanzmatrix mit den euklidischen Abständen
    DistanceTimeMatrix = DistanceMatrix/C + SystemDelayTime/1000;
    %Sample = round(DistanceTimeMatrix/Abtastintervall);

    %% Abtastfrequenz wird hier bestimmt

        %Zufällig im Intervall [-3;3]

        %Versuch den Abtastfehler einzubauen
    for i = 1:numSpeaker
        for j = 1:numMicros
             Sample(i,j) = round(DistanceTimeMatrix(i,j) /Abtastintervall);
             Abtastfehler = -3 + 6*rand;
             %Abtastfehler=0;
             t(i,j) = (Sample(i,j) + Abtastfehler) *Abtastintervall;
        end
    end    

    %% Hier wird die Zielfunktion definiert

    numTotal = numSpeaker * numMicros;      %so viel insgesamt
    iteration = 1;                          %iterationsvariable
    cnt = 0;                                %countervariable

    %Erste for Schleife stellt die Zielfunktion in Bezug zu den Lautsprechern auf
    %Zweite for Schleife stellt die Zielfunktion in Bezug aller unbekannten Mikrofone zu den
    %Lautsprechern auf
    while iteration < numTotal

        for m = 1 : numMicros - numUnknownMicros  
            %Hier werden einfach nur die euklidischen Abstände berechnet
            TargetFunction(iteration,1) =   sqrt(((MicrosPosition(m,1) - unknownVector(1, 1+(cnt*3)))^2) +...
                                            ((MicrosPosition(m,2)-unknownVector(1,2+(cnt*3)))^2) +...
                                            ((MicrosPosition(m,3)-unknownVector(1,3+(cnt*3)))^2)) -...
                                            ((t(1+cnt,m)-(unknownVector(1,overallUnknown)/1000))*C);
                                            %((DistanceTimeMatrix(1+cnt,m)-(unknownVector(1,overallUnknown)/1000))*C);
                                            
                                            
                                            
                                            %t(1+cnt) = mit Abtastfehler
                                            %und DistanceTimeMatrix = ohne

            %iterationsvariable geht einen höher, um die richtigen Positionen
            %zu belegen
            iteration = iteration + 1;
        end

        for n = overallUnknown - (3 * numUnknownMicros) : 3 : overallUnknown - 1
            %Hier werden einfach nur die euklidischen Abstände berechnet
            TargetFunction(iteration,1) =   sqrt(((unknownVector(1,n) - unknownVector(1, 1+(cnt*3)))^2) +...
                                            ((unknownVector(1,n+1)-unknownVector(1,2+(cnt*3)))^2) +...
                                            ((unknownVector(1,n+2)-unknownVector(1,3+(cnt*3)))^2)) -... 
                                            ((t(1+cnt,m+1)-(unknownVector(1,overallUnknown)/1000))*C);
                                            %((DistanceTimeMatrix(1+cnt,m+1)-(unknownVector(1,overallUnknown)/1000))*C);
                                            
                                            
                                            
                                            %t(1+cnt) = mit Abtastfehler
                                            %und DistanceTimeMatrix = ohn
            iteration = iteration + 1; 
            m = m + 1;
        end
        %countervariable einen höher, um den naechsten Lautsprecher zu benutzen
        cnt = cnt + 1;
    end 

    %% Startvektor festlegen

    xStart = transpose([vrSPT; vrUMPT; SystemDelayTime+1]);

    solveFunction = matlabFunction(TargetFunction,'Vars',{unknownVector});
    solution = fsolve(solveFunction, xStart);

    %% Ausgabe

    for a = numMicros - numUnknownMicros+1:numMicros
        UnknownMicrosPosition(a - numMicros + numUnknownMicros,:) = MicrosPosition(a,:);
    end

    b = 1;
    calculatedSpeakerPosition = zeros(numSpeaker, 3); % spart Rechenzeit da Speicher schon vor der Schleife angelegt ist
    for i = 1:numSpeaker
        for j = 1:3
            calculatedSpeakerPosition(i,j) = solution(b);
            b = b + 1;
        end
    end    

    b = numSpeaker * 3 + 1;
    calculatedMicroPosition = zeros(numUnknownMicros, 3); % spart Rechenzeit da Speicher schon vor der Schleife angelegt ist
    for i = 1:numUnknownMicros
        for j = 1:3
            calculatedMicroPosition(i,j) = solution(b);
            b = b + 1;
        end
    end    

    calculatedSpeakerPosition;
    errorSpeakerPositions = (SpeakersPosition(1:numSpeaker,:) - calculatedSpeakerPosition)*1000;

    calculatedMicroPosition;
    errorMicroPositions = (UnknownMicrosPosition - calculatedMicroPosition)*1000;

    calculatedSystemTime = solution(overallUnknown);
    errorSystemTime = SystemDelayTime - calculatedSystemTime;
    
    MaximumMicros(run, 1) = round(max(abs(errorMicroPositions(:,1))),3);    % 1. Spalte wird mit dem absoluten Maximum der X Koordinate der MicroPosition Matrix bespeichert pro Iterationsdurchlauf
    MaximumMicros(run, 2) = round(max(abs(errorMicroPositions(:,2))),3);    % 2. Spalte mit dem absoluten Maximum der Y Koordinate usw.
    MaximumMicros(run, 3) = round(max(abs(errorMicroPositions(:,3))),3);
    
    MaximumSpeaker(run, 1) = round(max(abs(errorSpeakerPositions(:,1))),3); % selbiges fuer die Lautsprecher
    MaximumSpeaker(run, 2) = round(max(abs(errorSpeakerPositions(:,2))),3);
    MaximumSpeaker(run, 3) = round(max(abs(errorSpeakerPositions(:,3))),3);

end

%% Ausgabe der Maxima sowie des Durchschnitts der Maxima

MaximumMicros
MaximumSpeaker

MaximumMicrosMean = mean(MaximumMicros)
MaximumSpeakerMean = mean(MaximumSpeaker)

%% Grafische Darstellung der Differenzmaxima

figure('Name', 'Maximum Micros Position Difference X', 'NumberTitle', 'off')
bar(MaximumMicros(:, 1))
title('Maximum Micros Position Difference X')
xlabel('number of runs')
ylabel('x Errors in mm')
%set(gca, 'YLim', [29.5 30.5])

figure('Name', 'Maximum Micros Position Difference Y', 'NumberTitle', 'off')
bar(MaximumMicros(:, 2))
title('Maximum Micros Position Difference Y')
xlabel('number of runs')
ylabel('y Errors in mm')
%set(gca, 'YLim', [19.5 20.5])

figure('Name', 'Maximum Micros Position Difference Z', 'NumberTitle', 'off')
bar(MaximumMicros(:, 3))
title('Maximum Micros Position Difference Z')
xlabel('number of runs')
ylabel('z Errors in mm')
%set(gca, 'YLim', [0 1])

figure('Name', 'Maximum Speakers Position Difference X', 'NumberTitle', 'off')
bar(MaximumSpeaker(:, 1))
title('Maximum Speakers Position Difference X')
xlabel('number of runs')
ylabel('x Errors in mm')
%set(gca, 'YLim', [0 0.3])

figure('Name', 'Maximum Speakers Position Difference Y ', 'NumberTitle', 'off')
bar(MaximumSpeaker(:, 2))
title('Maximum Speakers Position Difference Y')
xlabel('number of runs')
ylabel('y Errors in mm')
%set(gca, 'YLim', [0 0.3])

figure('Name', 'Maximum Speakers Position Difference Z', 'NumberTitle', 'off')
bar(MaximumSpeaker(:, 3))
title('Maximum Speakers Position Difference Z')
xlabel('number of runs')
ylabel('z Errors in mm')
%set(gca, 'YLim', [2.5 3.5])

%% Grafische Darstellung der Positionen

% figure('Name','Exakte Positionen','NumberTitle','off')
% 
% for v=1:numMicros
%     if v < numMicros - numUnknownMicros+1
%         scatter3(MicrosPosition(v,1), MicrosPosition(v,2), MicrosPosition(v,3), 'go', 'filled')
%         hold on
%         grid on
%     else
%         scatter3(MicrosPosition(v,1), MicrosPosition(v,2), MicrosPosition(v,3), 'ko', 'filled')
%         hold on
%         grid on
%     end
% end
% 
% for v = 1:numSpeaker
%     scatter3(SpeakersPosition(v,1),SpeakersPosition(v,2),SpeakersPosition(v,3),'bv','filled')
%     hold on
%     title('Mikrofon-und Lautsprecherpositionen')
%     xlabel('x-Achse')
%     ylabel('y-Achse')
%     zlabel('z-Achse')
%     set(gca,'XLim',[-40 40],'YLim',[-40 40],'ZLim',[-3 3])
%     grid on
% end
% 
% %% Grafische Darstellung der berechneten Positionen
% 
% figure('Name', 'Berechnete Positionen', 'NumberTitle', 'off')
% for v = 1:numUnknownMicros
%     scatter3(calculatedMicroPosition(v,1), calculatedMicroPosition(v,2), calculatedMicroPosition(v,3), 'ro', 'filled')
%     hold on
%     grid on
% end
% 
% for v = 1:numSpeaker
%     scatter3(calculatedSpeakerPosition(v,1), calculatedSpeakerPosition(v,2), calculatedSpeakerPosition(v,3), 'cv', 'filled')
%     hold on
%     title('Mikrofon-und Lautsprecherpositionen berechnet')
%     xlabel('x-Achse')
%     ylabel('y-Achse')
%     zlabel('z-Achse')
%     set(gca, 'XLim', [-40 40], 'YLim', [-40 40], 'ZLim', [-3 3])
%     grid on
% end