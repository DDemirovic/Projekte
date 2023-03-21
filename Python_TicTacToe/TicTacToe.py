import random

#dictionary for the board
theBoard = {'top-L': ' ', 'top-M': ' ', 'top-R': ' ',
            'mid-L': ' ', 'mid-M': ' ', 'mid-R': ' ',
            'bot-L': ' ', 'bot-M': ' ', 'bot-R': ' '}

#dictionary for the free spots on the board so I can randomize which spot the "AI" takes
freeSpotsOnBoard = {'top-L': '7', 'top-M': '8', 'top-R': '9',
                    'mid-L': '4', 'mid-M': '5', 'mid-R': '6',
                    'bot-L': '1', 'bot-M': '2', 'bot-R': '3'}

#Function that prints the board
def boardPrint(board):
    print(board['top-L'] + '|' + board['top-M'] + '|' + board['top-R'])
    print('-+-+-')
    print(board['mid-L'] + '|' + board['mid-M'] + '|' + board['mid-R'])
    print('-+-+-')
    print(board['bot-L'] + '|' + board['bot-M'] + '|' + board['bot-R'])

#Coinflip that decides if you, the player, are X or O
def playerOneRandomTeam():
    coinFlip = random.randint(1, 2)
    print("Coinflip ist: ", coinFlip)
    if 1 == coinFlip:
        teamDecider = "X" 
        print("You are playing: " + teamDecider)
    else:
        teamDecider = "O"
        print("You are playing: " + teamDecider)
    return teamDecider  #insanely important

#Function to set the team for the AI, if it is player vs. computer
def playerTwoTeam(realPlayerOne):
    if "X" == realPlayerOne:
        bot = "O"
        print("Bot is playing: ", bot)
    else:
        bot = "X"
        print("Bot plays: ", bot)
    return bot  #insanely important

#Function that checks if the user wants a random team or not (currently no use as of now, just an idea)
def wantToPlayRandom():
    print("Do you want to play a random team? Enter 'Y' for yes or 'N' for no.")
    takeInput = input()
    if "Y" == takeInput:
        print("You have chosen to play a random team.")
        playerOneRandomTeam()
    elif "N" == takeInput:
        print("You have chosen not to play a random team.")
        return #to do
    else:
        wantToPlayRandom()

#Function to check if a game is over
def gameStillGoing(theBoard):
    if (theBoard['top-L'] == theBoard['top-M']) and (theBoard['top-L'] == theBoard['top-R']) and (theBoard['top-L'] != ' '):
        print("Game over. The winner is: ", theBoard['top-L'])
        return False
    elif (theBoard['mid-L'] == theBoard['mid-M']) and (theBoard['mid-L'] == theBoard['mid-R']) and (theBoard['mid-L'] != ' '):
        print("Game over. The winner is: ", theBoard['mid-L'])
        return False
    elif (theBoard['bot-L'] == theBoard['bot-M']) and (theBoard['bot-L'] == theBoard['bot-R']) and (theBoard['bot-L'] != ' '):
        print("Game over. The winner is: ", theBoard['bot-L'])
        return False
    elif (theBoard['top-L'] == theBoard['mid-L']) and (theBoard['top-L'] == theBoard['bot-L']) and (theBoard['top-L'] != ' '):
        print("Game over. The winner is: ", theBoard['top-L'])
        return False
    elif (theBoard['top-M'] == theBoard['mid-M']) and (theBoard['top-M'] == theBoard['bot-M']) and (theBoard['top-M'] != ' '):
        print("Game over. The winner is: ", theBoard['top-M'])
        return False
    elif (theBoard['top-R'] == theBoard['mid-R']) and (theBoard['top-R'] == theBoard['bot-R']) and (theBoard['top-R'] != ' '):
        print("Game over. The winner is: ", theBoard['top-R'])
        return False
    elif (theBoard['top-L'] == theBoard['mid-M']) and (theBoard['top-L'] == theBoard['bot-R']) and (theBoard['top-L'] != ' '):
        print("Game over. The winner is: ", theBoard['top-L'])
        return False
    elif (theBoard['top-R'] == theBoard['mid-M']) and (theBoard['top-R'] == theBoard['bot-L']) and (theBoard['top-R'] != ' '):
        print("Game over. The winner is: ", theBoard['top-R'])
        return False
    elif (len(freeSpotsOnBoard) == 0):
        print("Game over. No one has won.")
        return False
    else:
        return True

#Function that takes an input in order to place a piece
def whichSpot():
    playerSpot = input()
    piecePlacer(playerTeam, playerSpot)     #playerTeam as of right now is a global variable, defined way down in the "initialize area"

#Function to check whose turn it is, lastTurn = variable that contains the info on who played last
def whoseTurn(lastTurn):
    if "X" == lastTurn:
        if "X" == playerTeam:
            print("Last turn was your turn. It is now the Bots turn.")
            randomPiecePlacer(botTeam)  #it was the players last turn, that's why we call that function so it simulates a total random move for the bot (aka dumb/super basic "AI")
        elif "O" == playerTeam:
            print("Last turn was the bots turn. It is now your turn.")
            whichSpot()
        else:
            print("Something went completely wrong.")
    else:
        if "O" == playerTeam:
            print("Last turn was your turn. It is now the Bots turn.")
            randomPiecePlacer(botTeam)  #it was the players last turn, that's why we call that function so it simulates a total random move for the bot (aka dumb/super basic "AI")
        elif "X" == playerTeam:
            print("Last turn was the bots turn. It is now your turn.")
            whichSpot()
        else:
            print("Something went completely wrong.")

#Function to place pieces, piece = either team X or team O, pieceSpot = the position said piece should be placed on
def piecePlacer(piece, pieceSpot):
    if ("7" == pieceSpot) or ('top-L' == pieceSpot):    #I have to check for the number AND top-L/M and so on because of the way I structured my boards, this seemed easier and quicker
        if theBoard['top-L'] == ' ':                    #If that spot is empty, go on and fill that spot with the piece
            theBoard['top-L'] = piece                       #piece gets placed on that spot    
            del freeSpotsOnBoard['top-L']                   #chosen position is deleted on that free board
            print("\n")
            boardPrint(theBoard)                            #new board is printed
            gameChecker = gameStillGoing(theBoard)          #check if there is a winner, boolean return
            if True == gameChecker:                         #if it is true (gameStillGoing), then go on
                print("\nPlace your piece")
                whoseTurn(piece)                            #continuation of the game, next players turn
        else:                                           #we get here if the chosen spot was already taken
            print("That spot is already taken. Try another spot.")
            whichSpot()      
    elif ("8" == pieceSpot) or ('top-M' == pieceSpot):  #repeat for every other spot on the board
        if theBoard['top-M'] == ' ':
            theBoard['top-M'] = piece                      
            del freeSpotsOnBoard['top-M']
            print("\n")
            boardPrint(theBoard)
            gameChecker = gameStillGoing(theBoard)
            if True == gameChecker:
                print("\nPlace your piece")
                whoseTurn(piece)
        else:
            print("That spot is already taken. Try another spot.")
            whichSpot()  
    elif ("9" == pieceSpot) or ('top-R' == pieceSpot):
        if theBoard['top-R'] == ' ':                   
            theBoard['top-R'] = piece                      
            del freeSpotsOnBoard['top-R']
            print("\n")
            boardPrint(theBoard)
            gameChecker = gameStillGoing(theBoard)
            if True == gameChecker:
                print("\nPlace your piece")
                whoseTurn(piece)
        else:
            print("That spot is already taken. Try another spot.")
            whichSpot()  
    elif ("4" == pieceSpot) or ('mid-L' == pieceSpot):
        if theBoard['mid-L'] == ' ':                   
            theBoard['mid-L'] = piece                      
            del freeSpotsOnBoard['mid-L']
            print("\n")
            boardPrint(theBoard)
            gameChecker = gameStillGoing(theBoard)
            if True == gameChecker:
                print("\nPlace your piece")
                whoseTurn(piece)
        else:
            print("That spot is already taken. Try another spot.")
            whichSpot()  
    elif ("5" == pieceSpot) or ('mid-M' == pieceSpot):
        if theBoard['mid-M'] == ' ':                   
            theBoard['mid-M'] = piece                      
            del freeSpotsOnBoard['mid-M']
            print("\n")
            boardPrint(theBoard)
            gameChecker = gameStillGoing(theBoard)
            if True == gameChecker:
                print("\nPlace your piece")
                whoseTurn(piece)
        else:
            print("That spot is already taken. Try another spot.")
            whichSpot() 
    elif ("6" == pieceSpot) or ('mid-R' == pieceSpot):
        if theBoard['mid-R'] == ' ':                   
            theBoard['mid-R'] = piece                      
            del freeSpotsOnBoard['mid-R']
            print("\n")
            boardPrint(theBoard)
            gameChecker = gameStillGoing(theBoard)
            if True == gameChecker:
                print("\nPlace your piece")
                whoseTurn(piece)
        else:
            print("That spot is already taken. Try another spot.")
            whichSpot() 
    elif ("1" == pieceSpot) or ('bot-L' == pieceSpot):
        if theBoard['bot-L'] == ' ':                   
            theBoard['bot-L'] = piece                      
            del freeSpotsOnBoard['bot-L']
            print("\n")
            boardPrint(theBoard)
            gameChecker = gameStillGoing(theBoard)
            if True == gameChecker:
                print("\nPlace your piece")
                whoseTurn(piece)
        else:
            print("That spot is already taken. Try another spot.")
            whichSpot() 
    elif ("2" == pieceSpot) or ('bot-M' == pieceSpot):
        if theBoard['bot-M'] == ' ':                   
            theBoard['bot-M'] = piece                      
            del freeSpotsOnBoard['bot-M']
            print("\n")
            boardPrint(theBoard)
            gameChecker = gameStillGoing(theBoard)
            if True == gameChecker:
                print("\nPlace your piece")
                whoseTurn(piece)
        else:
            print("That spot is already taken. Try another spot.")
            whichSpot() 
    elif ("3" == pieceSpot) or ('bot-R' == pieceSpot):
        if theBoard['bot-R'] == ' ':                   
            theBoard['bot-R'] = piece                      
            del freeSpotsOnBoard['bot-R']
            print("\n")
            boardPrint(theBoard)
            gameChecker = gameStillGoing(theBoard)
            if True == gameChecker:
                print("\nPlace your piece")
                whoseTurn(piece)
        else:
            print("That spot is already taken. Try another spot.")
            whichSpot() 
    else:
        print("Invalid position. You tried: ", piece, " on Pos.: ", pieceSpot)

#Function that places a piece on a free spot on the board
def randomPiecePlacer(botPiece):
    randomSpot = random.choice(list(freeSpotsOnBoard.keys()))                      #dict.keys() returns an iterable object, darum wird es zur Liste gemacht
    print("Bot will place his piece on ", randomSpot)
    piecePlacer(botPiece, randomSpot)
        
#Function that starts the game ///// to do
def startGame(): 
    return

#~~~~~~~~~~~~~~~~ Initialize Area ~~~~~~~~~~~~~~~~ 

print("\n\n\n\n\n\n")
playerTeam = playerOneRandomTeam()
botTeam = playerTwoTeam(playerTeam)

print("This is a game of Tic Tac Toe. You win if you place three of your pieces in a line (horizontally, vertically or diagonally).\
    \nPlace your pieces by typing the corresponding number.\n")
boardPrint(freeSpotsOnBoard)
print("Place your piece.")
whichSpot()