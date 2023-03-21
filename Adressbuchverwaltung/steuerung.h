#ifndef STEUERUNG_H
#define STEUERUNG_H

#include <QObject>
#include "mainwindow.h"
#include "dialog.h"
#include "liste.h"
#include "dialogdisplay.h"
#include "dateiverwaltung.h"

class steuerung : public QObject
{
    Q_OBJECT
public:
    explicit steuerung(QObject *parent = nullptr);
    void displayThisElement();
    void deleteThisElement();

private:
    Dialog *Dialog1;
    liste *liste1;
    kontakt kontakt1;
    MainWindow* MainWindow1;
    DialogDisplay *DialogDisplay1;
    dateiverwaltung *dateiverwaltung1;



signals:

public slots:
    void OnOkButtonPressed();
    void OnNewButtonPressed();
    void OnCloseDialog();
    void OnCancelButtonPressed();
    void OnDisplayButtonPressed();
    void OnCancelPressed();
    void OnNextButtonPressed();
    void OnPreButtonPressed();
    void OnSaveButtonPressed();
    void OnLoadButtonPressed();
    void OnDeleteAllButtonPressed();
    void OnDeleteDialog();
};

#endif // STEUERUNG_H
