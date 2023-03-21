#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <QDebug>
#include "dateiverwaltung.h"
#include "QString"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->new_2, SIGNAL (clicked()), this, SLOT (OnNewButtonPressed()));
    QObject::connect(ui->pushButton, SIGNAL (clicked()), this, SLOT (OnCancelButtonPressed()));
    QObject::connect(ui->display, SIGNAL (clicked()), this, SLOT (OnDisplayButtonPressed()));
    QObject::connect(ui->save, SIGNAL (clicked()), this, SLOT (OnSaveButtonPressed()));
    QObject::connect(ui->load, SIGNAL (clicked()), this, SLOT (OnLoadButtonPressed()));
    QObject::connect(ui->deleteList, SIGNAL (clicked()), this, SLOT (OnDeleteAllButtonPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTextLineEditAll(QString ref)
{
  ui->lineEdit_AllData->setText(ref);
}

void MainWindow::Duplikat(kontakt kontakt1)
{
    QString vorname = kontakt1.getVorname();
    QString nachname = kontakt1.getNachname();
    int alter = kontakt1.getAlter();
    QString statusVorname = QString("Der Kontakt %1, %2, %3 ist bereits Teil der Liste und wird nicht hinzugefügt.").arg(vorname).arg(nachname).arg(alter);
    QMessageBox::information(this, tr("Info"), statusVorname);
}

void MainWindow::OnNewButtonPressed()

{
    emit NewRequest();
}

void MainWindow::OnCancelButtonPressed()
{
    emit CancelRequest();
}

void MainWindow::OnDisplayButtonPressed()
{
    emit DisplayRequest();
}

void MainWindow::OnSaveButtonPressed()
{
    emit SaveRequest();
}

void MainWindow::OnLoadButtonPressed()
{
    emit LoadRequest();
}

void MainWindow::OnDeleteAllButtonPressed()
{
    emit DeleteAllRequest();
}

void MainWindow::OnList()
{
   QMessageBox::information(this, "TEST","TEST");
}
