#include "operations.h"

using namespace cv;

Operations::Operations():
    operationList((QStringList()
    << "Morphology"
    << "CvtColor"
    << "huy")){


}

QWidget* Operations::getLayouts(const QString* operation) const{

    QWidget* returnLayout;
    //look for operation

   if (*operation == "Morphology"){
       returnLayout = operationMorph();

   }
   else if (*operation == "CvtColor"){
       returnLayout = operationColor();

   }
   else{
       std::cout << "operation doesn't exist" << std::endl;
       return NULL;
    }


    //set layout name
    returnLayout->setObjectName(childName);

    //return

    return returnLayout;
}
QWidget* Operations::operationMorph() const{
    QWidget* opWidget = new QWidget();

    QVBoxLayout* currentLayout = new QVBoxLayout(opWidget);
    currentLayout->setDirection(QBoxLayout::TopToBottom);

    // Elements for the new layout
    QLabel* operationLabel = new QLabel("Operation:",opWidget);
    QComboBox* operation = new QComboBox(opWidget);
        operation->addItem("MORPH_OPEN");
        operation->addItem("MORPH_CLOSE");
        operation->addItem("MORPH_DILATE");
        operation->addItem("MORPH_ERODE");

    QLabel* elementLabel = new QLabel("Structuring Element:",opWidget);
    QComboBox* structuringElement = new QComboBox(opWidget);
    structuringElement->addItem("MORPH_RECT");

    QLabel* sizeLabel = new QLabel("Size:",opWidget);
    QSpinBox* size = new QSpinBox(opWidget);
    size->setValue(0);
    QLabel* iterationsLabel = new QLabel("Iterations:",opWidget);
    QSpinBox* iterations = new QSpinBox(opWidget);
    iterations->setValue(0);


    currentLayout->addWidget(operationLabel);
    currentLayout->addWidget(operation);
    currentLayout->addWidget(elementLabel);
    currentLayout->addWidget(structuringElement);

    QGridLayout* horizontal = new QGridLayout();
    horizontal->addWidget(sizeLabel,0,0,1,1);
    horizontal->addWidget(iterationsLabel,0,1,1,1);
    horizontal->addWidget(size,1,0,1,1);
    horizontal->addWidget(iterations,1,1,1,1);

    currentLayout->addLayout(horizontal);
    //currentLayout->addStretch();
    opWidget->setLayout(currentLayout);

    //return
    return opWidget;


}

QWidget* Operations::operationColor() const{
    QWidget* opWidget = new QWidget();
    // Layout Set-up
    QVBoxLayout* currentLayout = new QVBoxLayout(opWidget);

    //Item set-up

    // Color codes
    QLabel* conversionCode = new QLabel("Code:",opWidget);
    QComboBox* operation = new QComboBox(opWidget);
        operation->addItem("COLOR_RGB2GRAY ");
        operation->addItem("COLOR_GRAY2RGB ");
        operation->addItem("COLOR_RGB2HSV ");
        operation->addItem("COLOR_HSV2RGB ");
    //dstCn
    QLabel* dstCnLabel = new QLabel("Number of channels(0 for auto):",opWidget);
    QSpinBox* dstCn = new QSpinBox(opWidget);
        dstCn->setValue(0);

    // Build layout
    currentLayout -> addWidget(conversionCode);
    currentLayout -> addWidget(operation);
    currentLayout -> addWidget(dstCnLabel);
    currentLayout -> addWidget(dstCn);

    //currentLayout->addStretch();
    opWidget->setLayout(currentLayout);

    //return
    return opWidget;

 }
