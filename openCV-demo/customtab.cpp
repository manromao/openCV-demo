#include "customtab.h"
#include <QLabel>
#include <QLayout>
#include <ccombobox.h>


CustomTab::CustomTab(QWidget* parent) : QTabWidget(parent){
    QString text = op.operationList[0]; // Text of the Tab
    this->setTabText(text);

    //Set Visual stuff
    QLabel* operationsLabel = new QLabel("Function:",this);
    QFrame* frame = new QFrame(this);
    frame->setFrameShape(QFrame::HLine);
    QVBoxLayout* layout = new QVBoxLayout(this);    // Layout

    // Combo list
    CComboBox* combo  = new CComboBox(this);
    combo->addItems(op.operationList);
    connect(combo, &CComboBox::currentTextChanged,
            this, &CustomTab::onComboClicked);

    // Construct the layout
    layout->addWidget(operationsLabel);
    layout->addWidget(combo);
    layout->addWidget(frame);
    layout->addStretch();

    //send layout and tab to display in ui
    layout->addLayout(op.getLayouts(&text));

    this->setLayout(layout);
}

void CustomTab::onComboClicked(QString text){

}


CustomTab::~CustomTab(){}

void CustomTab::modifyTab() const{}

void CustomTab::setTabText(QString text){
    lastTabText = tabText;
    tabText = text;
}
QString  CustomTab::getTabText(){
    return (tabText);
}
