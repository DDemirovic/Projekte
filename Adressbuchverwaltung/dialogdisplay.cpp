#include "dialogdisplay.h"
#include "ui_dialogdisplay.h"
#include <QMessageBox>
#include "QDebug"


void DialogDisplay::clearAll()
{
    ui->lineEdit_Vorname->clear();
    ui->lineEdit_Nachname->clear();
    ui->lineEdit_Alter->clear();
}

DialogDisplay::DialogDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDisplay)
{
    ui->setupUi(this);
//    int number = liste1->count();
//    ui->pre->setEnabled(number > 1);
//    ui->next->setEnabled(number > 1);
    QObject::connect(ui->cancel, SIGNAL (clicked()), this, SLOT (OnClose()));
    QObject::connect(ui->next, SIGNAL (clicked()), this, SLOT (OnNext()));
    QObject::connect(ui->pre, SIGNAL (clicked()), this, SLOT (OnPre()));
    QObject::connect(ui->delete_2, SIGNAL (clicked()), this, SLOT (OnDelete()));
}

DialogDisplay::~DialogDisplay()
{
    delete ui;
}

void DialogDisplay::setAusgabeVorname(const QString &value)
{
    ausgabeVorname = value;
    ui->lineEdit_Vorname->setText(value);
}

void DialogDisplay::setAusgabeNachname(const QString &value)
{
    ausgabeNachname = value;
    ui->lineEdit_Nachname->setText(value);
}


void DialogDisplay::setAusgabeAlter(const int &value)
{
    ausgabeAlter = QString::number(value);
    ui->lineEdit_Alter->setText(ausgabeAlter);
}

void DialogDisplay::setDeleteButtonEnabled(bool enable)
{
    ui->delete_2->setEnabled(enable);
}

void DialogDisplay::setNextButtonEnabled(bool enable)
{
    ui->next->setEnabled(enable);
}

void DialogDisplay::setPreButtonEnabled(bool enable)
{
    ui->pre->setEnabled(enable);
}

void DialogDisplay::OnNext()
{
    emit nextButton();
}

void DialogDisplay::OnPre()
{
    emit preButton();
}

void DialogDisplay::OnDelete()
{
    emit deleteButton();
}

void DialogDisplay::OnClose()
{
    emit cancelButton();
}
