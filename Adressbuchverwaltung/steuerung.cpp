#include "steuerung.h"
#include "kontakt.h"
#include "qdebug.h"
#include "QMessageBox"
#include "QFile"

steuerung::steuerung(QObject *parent) : QObject(parent)
{
    MainWindow1 = new MainWindow;
    liste1 = new liste(this);
    MainWindow1->setGeometry(950, 450, 584, 209);
    MainWindow1->show();
    QObject::connect(MainWindow1, SIGNAL (NewRequest()), this, SLOT (OnNewButtonPressed()));
    QObject::connect(MainWindow1, SIGNAL (CancelRequest()), this, SLOT (OnCancelButtonPressed()));
    QObject::connect(MainWindow1, SIGNAL (DisplayRequest()), this, SLOT (OnDisplayButtonPressed()));
    QObject::connect(MainWindow1, SIGNAL (SaveRequest()), this, SLOT (OnSaveButtonPressed()));
    QObject::connect(MainWindow1, SIGNAL (LoadRequest()), this, SLOT (OnLoadButtonPressed()));
    QObject::connect(MainWindow1, SIGNAL (DeleteAllRequest()), this, SLOT (OnDeleteAllButtonPressed()));

//    dateiverwaltung1->LoadAll(MainWindow1);
}

void steuerung::OnOkButtonPressed()
{
    if(Dialog1->getVorname().length() > 0 && Dialog1->getNachname().length() > 0 && Dialog1->getAlter() > 0)
    {
        kontakt newKontakt (Dialog1->getVorname(), Dialog1->getNachname(), Dialog1->getAlter());
        liste1->InsertElement(newKontakt);
//        QMessageBox::information(MainWindow1, "Erfolg", "Erfolgreich hinzugefügt");
        Dialog1->clearAll();
    }
    else
    {
        QMessageBox::warning(MainWindow1, "Fehler", "Unvollständige/falsche Eingabe!");
    }
}

void steuerung::OnNewButtonPressed()
{
    Dialog1 = new Dialog;
    Dialog1->setModal(true);
    Dialog1->show();
    QObject::connect(Dialog1, SIGNAL (OkButton()), this, SLOT (OnOkButtonPressed()));
    QObject::connect(Dialog1, SIGNAL (cancelButton()), this, SLOT (OnCloseDialog()));
}

void steuerung::OnCloseDialog()
{
    Dialog1->close();
}

void steuerung::OnCancelButtonPressed()
{
    MainWindow1->close();
}

void steuerung::OnDisplayButtonPressed()
{
    if(liste1->count() == 0)
        QMessageBox::warning(MainWindow1, "Fehler", "Liste ist leer!");
    else
    {
        DialogDisplay1 = new DialogDisplay;
        DialogDisplay1->setModal(true);
        DialogDisplay1->show();
        displayThisElement();
        if(liste1->count() == 1)
        {
            DialogDisplay1->setNextButtonEnabled(false);
            DialogDisplay1->setPreButtonEnabled(false);
        }
        QObject::connect(DialogDisplay1, SIGNAL (cancelButton()), this, SLOT (OnCancelPressed()));
        QObject::connect(DialogDisplay1, SIGNAL (nextButton()), this, SLOT (OnNextButtonPressed()));
        QObject::connect(DialogDisplay1, SIGNAL (preButton()), this, SLOT (OnPreButtonPressed()));
        QObject::connect(DialogDisplay1, SIGNAL (deleteButton()), this, SLOT (OnDeleteDialog()));
    }
}

void steuerung::OnCancelPressed()
{
   liste1->SetFirstElement();
   DialogDisplay1->close();
}

void steuerung::OnNextButtonPressed()
{
    liste1->getnext();
    if(liste1->iterator == liste1->lastElement)
    {
        DialogDisplay1->setNextButtonEnabled(false);
        DialogDisplay1->setPreButtonEnabled(true);
    }
    if(liste1->iterator->pre != nullptr)
    {
        DialogDisplay1->setPreButtonEnabled(true);
    }

    displayThisElement();
}

void steuerung::OnPreButtonPressed()
{
    liste1->getpre();
    if(liste1->iterator->next != nullptr)
    {
        DialogDisplay1->setNextButtonEnabled(true);
    }
    if(liste1->iterator == liste1->getStartList())
    {
        DialogDisplay1->setPreButtonEnabled(false);
        DialogDisplay1->setNextButtonEnabled(true);
    }
    displayThisElement();
}

void steuerung::displayThisElement()
{
    DialogDisplay1->setAusgabeVorname(liste1->displayGetElement().getVorname());
    DialogDisplay1->setAusgabeNachname(liste1->displayGetElement().getNachname());
    DialogDisplay1->setAusgabeAlter(liste1->displayGetElement().getAlter());
}

void steuerung::deleteThisElement()
{
    liste1->deleteValue(kontakt1);
}

void steuerung::OnSaveButtonPressed()
{
   dateiverwaltung1->save(liste1);
//   dateiverwaltung1->LoadAll(MainWindow1);
}

void steuerung::OnLoadButtonPressed()
{
    dateiverwaltung1->load(liste1);
}

void steuerung::OnDeleteAllButtonPressed()
{
    liste1->deleteAll();
}

void steuerung::OnDeleteDialog()
{
    qDebug () << "---CUT---";
        if(liste1->IsEmpty())
        {
            DialogDisplay1->setDeleteButtonEnabled(false);
            DialogDisplay1->setNextButtonEnabled(false);
            DialogDisplay1->setPreButtonEnabled(false);
            QMessageBox::warning(MainWindow1, "Fehler", "Liste ist leer!");
        }
        else
        {
            deleteThisElement();
            if(liste1->iterator->next != nullptr)
                liste1->getnext();
            else {
                liste1->getpre();
            }
            displayThisElement();
        }
}


