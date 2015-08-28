#ifndef CCOMBOBOX_H
#define CCOMBOBOX_H

#include <QString>
#include <QComboBox>
#include <QMouseEvent>

class CComboBox : public QComboBox
{

public:
    CComboBox(QWidget *parent = 0);
    QString GetPreviousText();

protected:
    void onComboClicked(QMouseEvent *e);
private:
    QString m_PreviousText;
};
#endif // CCOMBOBOX_H
