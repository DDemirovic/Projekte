#ifndef LISTE_H
#define LISTE_H

#include <QObject>
#include "kontakt.h"
#include "mainwindow.h"

struct Listenelement
{
    Listenelement* pre;
    kontakt person;
    Listenelement* next;

    void setPerson(const kontakt &value);
    kontakt getPerson() const;
};

class liste : public QObject
{
    Q_OBJECT
public:
    explicit liste(QObject *parent = nullptr);
    Listenelement *lastElement;
    Listenelement *iterator;


    kontakt displayGetElement();
    void SetFirstElement();
    void getnext();
    void getpre();
    liste();
    liste (Listenelement person);
    void displayList();
    void displayListReverse();
    int  count();
    bool IsEmpty();
    void InsertElement(kontakt kontakt1);
    void deleteAll();
    void deletePosition(int);
    void deleteValue(kontakt kontakt1);
    void insertAtPosition(int position, Listenelement);
    Listenelement RemoveFirstElement();
    Listenelement *getStartList() const;

    void setStartList(Listenelement *value);


    void setIterator(Listenelement *value);

private:
    Listenelement *startList;
    Listenelement *endList;

    void initList();


signals:

public slots:

};

#endif // LISTE_H
