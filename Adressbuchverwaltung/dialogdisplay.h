#ifndef DIALOGDISPLAY_H
#define DIALOGDISPLAY_H
#include "liste.h"
#include <QDialog>

namespace Ui {
class DialogDisplay;
}

class DialogDisplay : public QDialog
{
    Q_OBJECT

public:

    void clearAll();

    explicit DialogDisplay(QWidget *parent = nullptr);
    ~DialogDisplay();


    void setAusgabeVorname(const QString &value);

    void setAusgabeNachname(const QString &value);

    void setAusgabeAlter(const int &value);

    void setDeleteButtonEnabled(bool enable);
    void setNextButtonEnabled(bool enable);
    void setPreButtonEnabled(bool enable);

private:
    Ui::DialogDisplay *ui;
    liste *liste1;
    DialogDisplay *DialogDisplay1;
    QString ausgabeVorname;
    QString ausgabeNachname;
    QString ausgabeAlter;

signals:
    void nextButton();
    void preButton();
    void cancelButton();
    void deleteButton();

public slots:
    void OnClose();
    void OnNext();
    void OnPre();
    void OnDelete();

};

#endif // DIALOGDISPLAY_H
