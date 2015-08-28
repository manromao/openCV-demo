#include "operations.h"

using namespace cv;

Operations::Operations():
    operationList((QStringList()
    << "hey"
    << "hoy"
    << "huy")){


}

QVBoxLayout* Operations::switchOperations() const{

    return operationMorph();
}
QVBoxLayout* Operations::operationMorph() const{

    QVBoxLayout* currentLayout = new QVBoxLayout();
    // Elements for the new layout
    QLabel* operationLabel = new QLabel("Operation:");
    QComboBox* operation = new QComboBox();
        operation->addItem("MORPH_OPEN");
        operation->addItem("MORPH_CLOSE");
        operation->addItem("MORPH_DILATE");
        operation->addItem("MORPH_ERODE");

    QLabel* elementLabel = new QLabel("Structuring Element:");
    QComboBox* structuringElement = new QComboBox();
    structuringElement->addItem("MORPH_RECT");

    QLabel* sizeLabel = new QLabel("Size:");
    QSpinBox* size = new QSpinBox();
    size->setValue(0);
    QLabel* iterationsLabel = new QLabel("Iterations:");
    QSpinBox* iterations = new QSpinBox();
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
    currentLayout->addStretch();

    return currentLayout;


}
