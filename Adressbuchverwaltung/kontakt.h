#ifndef KONTAKT_H
#define KONTAKT_H
#include <QString>

class kontakt
{
public:

    kontakt();
    kontakt(QString vorname1, QString nachname2, int alter1);
    int getAlter() const;
    void setAlter(int value);

    QString getNachname() const;
    void setNachname(const QString &value);

    QString getVorname() const;
    void setVorname(const QString &value);

    kontakt (const kontakt &b);


private:
    QString vorname;
    QString nachname;
    int alter;
};

#endif // KONTAKT_H
