#include "customtab.h"

#include <QLabel>
#include <QLayout>
#include <QComboBox>

// Public
CustomTab::CustomTab(QTabWidget* parent) : QTabWidget(parent){

    QString* currentOperation = new QString(op.operationList[0]); // Change to stack
    this->setTabText(currentOperation);

    QVBoxLayout* tabLayout = new QVBoxLayout(this);
    tabLayout->setDirection(QBoxLayout::TopToBottom);
    tabLayout->addWidget(getMainBox(),0,Qt::AlignTop);

    //send layout and tab to display in ui
    modifyTab(currentOperation);

    connect(&op,&Operations::performOperationEvent,
            this, &CustomTab::onDataChanged);
    delete(currentOperation);

}

CustomTab::~CustomTab(){
    std::cout << "Custom tab destructor!" << std::endl;
}

QString  CustomTab::getTabText(){
    return (tabText);
}

cv::Mat CustomTab::doOperation(cv::Mat image){
    cv::Mat ret = op.switchOperations(image);
    return(ret);
}

//Private:
QTabWidget* CustomTab::getParent(){

    return(qobject_cast<QTabWidget*> (this->parentWidget()));
}

QWidget* CustomTab::getMainBox() {
    //Set Visual stuff
    QWidget* mainBox = new QWidget(this);

    QLabel* operationsLabel = new QLabel("Function:",mainBox);
    QFrame* frame = new QFrame(mainBox);
    frame->setFrameShape(QFrame::HLine);
    QVBoxLayout* layout = new QVBoxLayout(mainBox);    // Layout
    layout->setObjectName("mainLayout");
    layout->setDirection(QBoxLayout::TopToBottom);

    // Combo list
    QComboBox* combo  = new QComboBox(mainBox);
    combo->addItems(op.operationList);
    connect(combo, &QComboBox::currentTextChanged,
            this, &CustomTab::onComboClicked);

    // Construct the layout
    layout->addWidget(operationsLabel);
    layout->addWidget(combo);
    layout->addWidget(frame);



    return mainBox;

}

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

// Slots
void CustomTab::onComboClicked(QString newOperation){
    // Active only when a new operation is selected
    this->modifyTab(&newOperation);
    emit onTabNameChanged();
    emit newOperationEvent();
}

void CustomTab::onDataChanged(){
    emit newOperationEvent();
}

void CustomTab::onNewOperation(cv::Mat image){
    doOperation( image);
}
