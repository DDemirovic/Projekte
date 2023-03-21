#include "dialog.h"
#include "ui_dialog.h"
#include "QDebug"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_2, SIGNAL (clicked()), this, SLOT (OnReadOut()));
    QObject::connect(ui->pushButton, SIGNAL (clicked()), this, SLOT (Onclose()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::clearAll()
{
    ui->lineEdit_vorname->clear();
    ui->lineEdit_nachname->clear();
    ui->lineEdit_Alter->clear();
}

QString Dialog::getVorname() const
{
    return vorname;
}

QString Dialog::getNachname() const
{
    return nachname;
}

void Dialog::setVorname(const QString &value)
{
    vorname = value;
}

void Dialog::setNachname(const QString &value)
{
    nachname = value;
}

int Dialog::getAlter() const
{
    return alter;
}

void Dialog::setAlter(int value)
{
    alter = value;
}

void Dialog::Onclose()
{
    emit cancelButton();
}

void Dialog::OnReadOut()
{

    vorname = ui->lineEdit_vorname->text();
    nachname = ui->lineEdit_nachname->text();
    alter = ui->lineEdit_Alter->text().toInt();
    emit OkButton();
}




