#include "dateiverwaltung.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

dateiverwaltung::dateiverwaltung(QObject *parent) : QObject(parent)
{

}

void dateiverwaltung::save(liste *liste1)
{
    QFile file("C:/Users/Dmitrij/Desktop/QT/mylist2.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox msgBox;
        msgBox.setText("Fehler");
        msgBox.exec();
    }
    QTextStream out(&file);
    liste1->iterator = liste1->getStartList();
    while(liste1->iterator != nullptr)
    {
        QString text1 = liste1->iterator->person.getVorname();
        QString text2 = liste1->iterator->person.getNachname();
        int text3 = liste1->iterator->person.getAlter();
        out << text1 << "," << text2 << "," << text3 << endl;
        if(liste1->iterator->next != nullptr)
            liste1->iterator = liste1->iterator->next;
        else
            return;
    }
    file.flush();
    file.close();
}

void dateiverwaltung::load(liste *liste1)
{
    if(liste1->IsEmpty())
    {
        QFile file("C:/Users/Dmitrij/Desktop/QT/mylist2.txt");
        if(!file.open(QFile::ReadOnly | QIODevice::Text))
        {
            return;

        }
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            QStringList IstLine = line.split(",");
            QString vorname_ = IstLine.at(0);
            QString nachname_ = IstLine.at(1);
            QString alter_ = IstLine.at(2);

            kontakt neuerKontakt (vorname_, nachname_, alter_.toInt());

            liste1->InsertElement(neuerKontakt);

        }
        file.close();
        return;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setInformativeText("Liste ist nicht leer. Zuletzt gespeicherte Daten laden und hinten einfügen?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int reply = msgBox.exec();
        if(reply == QMessageBox::Yes)
        {
            QFile file("C:/Users/Dmitrij/Desktop/QT/mylist2.txt");
            if(!file.open(QFile::ReadOnly | QIODevice::Text))
            {
                return;
            }
            QTextStream in(&file);
            while(!in.atEnd())
            {
                QString line = in.readLine();
                QStringList IstLine = line.split(",");
                QString vorname_ = IstLine.at(0);
                QString nachname_ = IstLine.at(1);
                QString alter_ = IstLine.at(2);

                kontakt neuerKontakt (vorname_, nachname_, alter_.toInt());
                liste1->InsertElement(neuerKontakt);
            }

            QMessageBox msgBox;
            msgBox.setInformativeText("Liste wurde erneut geladen und ans Ende der Liste angefügt!");
            file.close();
            return;
       }
    }   
    return;
}


