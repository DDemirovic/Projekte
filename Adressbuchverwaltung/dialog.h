#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void clearAll();

    QString getVorname() const;

    QString getNachname() const;

    void setVorname(const QString &value);

    void setNachname(const QString &value);

    int getAlter() const;
    void setAlter(int value);

private:
    Ui::Dialog *ui;
    QString vorname;
    QString nachname;
    int alter;

signals:
    void OkButton();
    void cancelButton();

public slots:
    void Onclose();
    void OnReadOut();
};

#endif // DIALOG_H
