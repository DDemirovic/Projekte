#include "liste.h"
#include "dialog.h"
#include <iostream>
#include "qdebug.h"
#include "string.h"
using namespace std;

liste::liste(QObject *parent) : QObject(parent)
{
    this->initList();
}

void liste::setIterator(Listenelement *value)
{
    iterator = value;
}

kontakt liste::displayGetElement()
{
    if (!IsEmpty())
        return iterator->person;
    else
    {
        kontakt maxMustermann("Leer", "Leer", 0);
        return maxMustermann;
    }
}

void liste::SetFirstElement()
{
    setIterator(startList);
}

void liste::getnext()
{
    if(iterator->next != nullptr)
        iterator = iterator->next;
}

void liste::getpre()
{
    if(iterator->pre != nullptr)
        iterator = iterator->pre;
}

void liste::initList()
{
    startList = nullptr;
    endList = nullptr;
    lastElement = nullptr;
    iterator = nullptr;
}

liste::liste()
{
    this->initList();
}

//liste::liste(Listenelement person)
//{
//    this->person = person;
//}

bool liste::IsEmpty()
{
    if (startList != nullptr)
        return false;
    else
        return true;
}

void liste::displayList()
{
    Listenelement* element = startList;
    cout << "Liste:" << std::endl;
    while (element != nullptr)
    {
        qDebug() << element->getPerson().getVorname();
        qDebug() << element->getPerson().getNachname();
        qDebug() << element->getPerson().getAlter();
        element = element->next;
    }
    cout << endl;
}

void liste::displayListReverse()
{
    Listenelement* element = lastElement;
    cout << "Liste:" << std::endl;
    while (element != nullptr)
    {
        qDebug() << element->getPerson().getVorname() << " ";
        qDebug() << element->getPerson().getNachname()<< " ";
        qDebug() << element->getPerson().getAlter() << " ";
        element = element->pre;
    }
    cout << endl;
}

int liste::count()
{
    Listenelement *element = startList;
    int count = 0;
    while(element != nullptr)
    {
        count++;
        element = element->next;
    }
    return count;
}

void liste::InsertElement(kontakt kontakt1)

{
    Listenelement* element = startList;
    Listenelement* check = startList;

    if(IsEmpty())
    {
        Listenelement* neu = new Listenelement;

        neu->person.setVorname(kontakt1.getVorname());
        neu->person.setNachname(kontakt1.getNachname());
        neu->person.setAlter(kontakt1.getAlter());

        neu->next = endList;
        neu->pre = startList;
        startList = neu;
        lastElement = neu;
        iterator = startList;
    }
    else
    {
        while(element->next != nullptr)
        {
            element = element->next;
        }
        Listenelement* neu = new Listenelement;

        while(check != nullptr)
        {
            if(kontakt1.getAlter() == check->getPerson().getAlter() && kontakt1.getVorname() == check->getPerson().getVorname() && kontakt1.getNachname() == check->getPerson().getNachname())
            {
                MainWindow* mw = qobject_cast <MainWindow*> (parent());
                mw->Duplikat(kontakt1);
                return;
         }
      check = check->next;
      }
      neu->person.setVorname(kontakt1.getVorname());
      neu->person.setNachname(kontakt1.getNachname());
      neu->person.setAlter(kontakt1.getAlter());

      neu->next = endList;
      neu->pre = element;
      element->next = neu;
      lastElement = neu;
    }
}

void liste::deleteAll()
{
    Listenelement* deleteElement = nullptr;
    Listenelement* element = lastElement;

    while (element != nullptr)
    {
        deleteElement = element;
        element = element->pre;
        delete  deleteElement;
    }

     startList = nullptr;
     endList = nullptr;
     lastElement = nullptr;
}

void liste::deletePosition(int position)
{
    if ((position > count()) || (position < 1))
    {
        std::cout << "Es wird nichts geloescht!" << '\n';
        return;
    }

    Listenelement* deleteElement = startList;

    if (deleteElement==nullptr)
    {
        cout << "Liste ist bereits leer!" << std::endl;
        return;
    }

    Listenelement* hilf = nullptr;

    if(position == 1)
    {
        if(deleteElement->next == nullptr)
        {
            deleteAll();
            return;
        }
        startList = deleteElement->next;
        hilf = startList;
        hilf->pre = nullptr;
        delete deleteElement;
    }
    else if (position == count())
    {
        Listenelement* zeiger = lastElement;
        lastElement = zeiger->pre;
        lastElement->next = endList;
    }
    else
        {
            for(int i = 0; i < position -1; i++)
            {
                deleteElement = deleteElement->next;
            }
           deleteElement->pre->next = deleteElement->next;
           deleteElement->next->pre = deleteElement->pre;
           delete deleteElement;
        }
}

void liste::deleteValue(kontakt kontakt1)
{
    Listenelement* element = startList;
    if (element==nullptr)
    {
        cout << "Keine Elemente vorhanden!" << std::endl;
        return;
    }
    int counter = 1;
    while (element!=nullptr)
    {
        if (element->person.getAlter() == iterator->getPerson().getAlter() && element->person.getVorname() == iterator->getPerson().getVorname() && element->person.getNachname() == iterator->getPerson().getNachname())
        {
            deletePosition(counter);
            return;
        }
        else
        {
            counter++;
            element = element->next;
        }
    }
    cout << "Person: " << &kontakt1 << " nicht gefunden!" << endl;
}

//void liste::insertAtPosition(int position, Listenelement person)
//{
//    Listenelement* element = startList;

//    if((IsEmpty()) || (position>count()))
//    {
//       InsertElement(kontakt1);
//       return;
//    }

//    if (position < 1)
//    {
//        cout << "Ungültige Position!" << endl;
//        return;
//    }

//    if (position == 1)
//    {
//       Listenelement* neu = new Listenelement(person);
//       neu->next = startList;
//       neu->pre  = nullptr;
//       neu->next->pre = neu;
//       startList = neu;
//    }
//    else
//    {
//        for(int i = 1; i < position; i++)
//        {
//            element = element->next;
//        }
//        Listenelement* neu = new Listenelement(person);
//        neu->next = element;
//        neu->pre = element->pre;
//        element->pre->next = neu;
//        element->pre = neu;
//    }
//}

//Listenelement liste::RemoveFirstElement()
//{
//    Listenelement* element = lastElement;
//    if(IsEmpty())
//       return *element;
//    else if(lastElement == startList)
//    {
//        startList = nullptr;
//        endList = nullptr;
//        return *lastElement;
//    }
//    else
//    {
//        while(element != startList)
//        {
//             element = element->pre;
//        }

//        startList = element->next;
//        element->next->pre = nullptr;
//        return *element;
//    }
//}

Listenelement *liste::getStartList() const
{
    return startList;
}

void liste::setStartList(Listenelement *value)
{
    startList = value;
}

kontakt Listenelement::getPerson() const
{
    return person;
}

void Listenelement::setPerson(const kontakt &value)
{
    person.setVorname(value.getVorname());
    person.setAlter(value.getAlter());
    person.setNachname(value.getNachname());
}
