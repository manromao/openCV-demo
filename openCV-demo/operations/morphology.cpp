#include "morphology.h"
#include <QDebug>
using namespace cv;

Morphology::Morphology(Function *parent) : Function(parent),
    operationsList(QStringList()
               << "MORPH_ERODE"
               << "MORPH_DILATE"
               << "MORPH_OPEN"
               << "MORPH_CLOSE"
               << "MORPH_GRADIENT"
               << "MORPH_TOPHAT"
               << "MORPH_BLACKHAT"){}


Morphology::~Morphology(){
    qDebug() << "CvtColor destructor";
}

//Public
QWidget* Morphology::getLayout(const Operations* op){

    QWidget* opWidget = new QWidget();

    QVBoxLayout* currentLayout = new QVBoxLayout(opWidget);
    currentLayout->setDirection(QBoxLayout::TopToBottom);

    // Elements for the new layout
    // Operation
    QLabel* operationLabel = new QLabel("Operation:",opWidget);
    operationCombo = new QComboBox(opWidget);
    operationCombo->addItems(operationsList);

    //Structuring element
    QLabel* elementLabel = new QLabel("Structuring Element:",opWidget);
    structuringElement = new QComboBox(opWidget);
    structuringElement->addItem("MORPH_RECT");

    //Size
    QLabel* sizeLabel = new QLabel("Size:",opWidget);
    size = new QSpinBox(opWidget);
    size->setMinimum(1);
    size->setValue(1);

    // iterations
    QLabel* iterationsLabel = new QLabel("Iterations:",opWidget);
    iterations = new QSpinBox(opWidget);
    iterations->setValue(1);

    // set Layout
    currentLayout->addWidget(operationLabel);
    currentLayout->addWidget(operationCombo);
    currentLayout->addWidget(elementLabel);
    currentLayout->addWidget(structuringElement);

    //SubLayout
    QGridLayout* horizontal = new QGridLayout();
    horizontal->addWidget(sizeLabel,0,0,1,1);
    horizontal->addWidget(iterationsLabel,0,1,1,1);
    horizontal->addWidget(size,1,0,1,1);
    horizontal->addWidget(iterations,1,1,1,1);

    currentLayout->addLayout(horizontal);
    opWidget->setLayout(currentLayout);

    //Connects
    QObject::connect(operationCombo,&QComboBox::currentTextChanged,op,&Operations::onSignalReceived);
    QObject::connect(structuringElement,&QComboBox::currentTextChanged,op,&Operations::onSignalReceived);
    QObject::connect(size,SIGNAL_CAST_INT(&QSpinBox::valueChanged),op,&Operations::onSignalReceived);
    QObject::connect(iterations,SIGNAL_CAST_INT(&QSpinBox::valueChanged),op,&Operations::onSignalReceived);

    //return
    return opWidget;

}

cv::Mat Morphology::processImage(cv::Mat image) const{
    int code = getOperationCode();
    int shape = getStructuringElement();
    int isize  = getSize();
    int iterat = getIterations();
    Mat element = cv::getStructuringElement(shape,cv::Size(isize,isize));

    cv::morphologyEx(image,image,code,element,Point(-1,-1),iterat,
                     BORDER_CONSTANT,morphologyDefaultBorderValue());

    return image;
}

// Private
int Morphology::getOperationCode() const{
    QString op = operationCombo->currentText();
    int index = operationsList.indexOf(op);
    int code;

    switch(index){
//     "MORPH_ERODE"
    case 0:
        code = cv::MORPH_ERODE;
        break;
//     "MORPH_DILATE"
    case 1:
        code = cv::MORPH_DILATE;
        break;
//     "MORPH_OPEN"
    case 2:
        code = cv::MORPH_OPEN;
        break;
//     "MORPH_CLOSE"
    case 3:
        code = cv::MORPH_CLOSE;
        break;
//     "MORPH_GRADIENT"
    case 4:
        code = cv::MORPH_GRADIENT;
        break;
//     "MORPH_TOPHAT"
    case 5:
        code = cv::MORPH_TOPHAT;
        break;
//     "MORPH_BLACKHAT"
    case 6:
        code = cv::MORPH_BLACKHAT;
        break;
    default:
        code=0;
        break;
    }

    return code;

}

int Morphology::getStructuringElement() const{
    return (cv::MORPH_RECT);
}

int Morphology::getSize() const{
    return(size->value());
}

int Morphology::getIterations() const{
    return (iterations->value());
}
