#include "mainwindow.h"
#include <QApplication>
#include "steuerung.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    steuerung st1;

    return a.exec();
}
