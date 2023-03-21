#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QMessageBox>
#include "kontakt.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Duplikat(kontakt kontakt1);

    void setTextLineEditAll(QString ref);

private:
    Ui::MainWindow *ui;
    QString eingabeVorname;
    QString eingabeNachname;
    QString eingabeAlter;

signals:
    void NewRequest();
    void CancelRequest();
    void DisplayRequest();
    void SaveRequest();
    void LoadRequest();
    void DeleteAllRequest();
    void OpenList();

public slots:
    void OnNewButtonPressed();
    void OnCancelButtonPressed();
    void OnDisplayButtonPressed();
    void OnSaveButtonPressed();
    void OnLoadButtonPressed();
    void OnDeleteAllButtonPressed();
    void OnList();
};

#endif // MAINWINDOW_H
