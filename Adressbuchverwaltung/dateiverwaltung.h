#ifndef DATEIVERWALTUNG_H
#define DATEIVERWALTUNG_H

#include "liste.h"


class dateiverwaltung : public QObject
{
    Q_OBJECT
public:
    explicit dateiverwaltung(QObject *parent = nullptr);

    void save(liste *liste1);
    void load(liste *liste1);
    void LoadAll(MainWindow *mw);

private:

signals:

public slots:
};

#endif // DATEIVERWALTUNG_H
