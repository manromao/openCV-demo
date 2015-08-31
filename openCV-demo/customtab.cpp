#include "customtab.h"
#include <QLabel>
#include <QLayout>
#include <ccombobox.h>



CustomTab::CustomTab(QTabWidget* parent) : QTabWidget(parent){

    QString* currentOperation = new QString(op.operationList[0]);
    this->setTabText(currentOperation);

    QVBoxLayout* tabLayout = new QVBoxLayout(this);
    tabLayout->setDirection(QBoxLayout::TopToBottom);
    tabLayout->addWidget(getMainBox(),0,Qt::AlignTop);
    //this->setLayout(tabLayout);

    //send layout and tab to display in ui
    modifyTab(currentOperation);

    parent->addTab(this, this->tabText);


}

void CustomTab::onComboClicked(QString newOperation){
    // Active only when a new operation is selected
        this->modifyTab(&newOperation);

}


CustomTab::~CustomTab(){}


void CustomTab::modifyTab(QString* newOperation){
    // Delete old layout
    this->deleteOperationBox();

    // Add layout for new operations
    this->setOperationBox(newOperation);

    // Change tab name
    this->setTabText(newOperation);
}

void CustomTab::setTabText(QString* text){

    lastTabText = tabText;
    tabText = *text;
}
QString  CustomTab::getTabText(){
    return (tabText);
}

void CustomTab::deleteOperationBox(){

   QWidget* del = this->findChild<QWidget*>(op.childName);
   QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(this->layout());
   layout->removeWidget(del);


   delete del;
}

void CustomTab::setOperationBox(const QString *operation){
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(this->layout());
    QWidget* operationBox = op.getLayouts(operation);
    operationBox->setParent(this);

    layout->addWidget(operationBox,10, Qt::AlignTop);

}

QWidget* CustomTab::getMainBox() {
    // Text of the Tab


    //Set Visual stuff
    QWidget* mainBox = new QWidget(this);

    QLabel* operationsLabel = new QLabel("Function:",mainBox);
    QFrame* frame = new QFrame(mainBox);
    frame->setFrameShape(QFrame::HLine);
    QVBoxLayout* layout = new QVBoxLayout(mainBox);    // Layout
    layout->setObjectName("mainLayout");
    layout->setDirection(QBoxLayout::TopToBottom);

    // Combo list
    CComboBox* combo  = new CComboBox(mainBox);
    combo->addItems(op.operationList);
    connect(combo, &CComboBox::currentTextChanged,
            this, &CustomTab::onComboClicked);

    // Construct the layout
    layout->addWidget(operationsLabel);
    layout->addWidget(combo);
    layout->addWidget(frame);



    return mainBox;

}
