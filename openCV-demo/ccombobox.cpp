#include "ccombobox.h"

CComboBox::CComboBox(QWidget *parent) : QComboBox(parent)
{
    m_PreviousText = "0";
}


QString CComboBox::GetPreviousText() { return m_PreviousText; }


void CComboBox::onComboClicked(QMouseEvent *e)
{
    m_PreviousText = this->currentText();
    //QComboBox::onComboClicked(e);
}



