#include "kontakt.h"

kontakt::kontakt()
{
//    vorname = "Jack";
//    nachname = "Sparrow";
//    alter = 55;
}

kontakt::kontakt(QString vorname1, QString nachname2, int alter1)
{
    vorname = vorname1;
    nachname = nachname2;
    alter = alter1;
}

int kontakt::getAlter() const
{
    return alter;
}

void kontakt::setAlter(int value)
{
    alter = value;
}

QString kontakt::getNachname() const
{
    return nachname;
}

void kontakt::setNachname(const QString &value)
{
    nachname = value;
}

QString kontakt::getVorname() const
{
    return vorname;
}

void kontakt::setVorname(const QString &value)
{
    vorname = value;
}

kontakt::kontakt(const kontakt &b)
{
    this->vorname = b.vorname;
    this->nachname = b.nachname;
    this->alter = b.alter;
}
