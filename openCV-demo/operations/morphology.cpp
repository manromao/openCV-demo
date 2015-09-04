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
    qDebug() << "Morphology destructor";
}

//Public
QWidget* Morphology::getLayout(const Operations* op){

    mainBox = new QWidget();

    QVBoxLayout* currentLayout = new QVBoxLayout(mainBox);
    currentLayout->setDirection(QBoxLayout::TopToBottom);

    // Elements for the new layout
    // Operation
    QLabel* operationLabel = new QLabel("Operation:",mainBox);
    operationCombo = new QComboBox(mainBox);
    operationCombo->addItems(operationsList);

    //Structuring element
    QLabel* elementLabel = new QLabel("Structuring Element:",mainBox);
    structuringElement = new QComboBox(mainBox);
    structuringElement->addItem("MORPH_RECT");

    //Size
    QLabel* sizeLabel = new QLabel("Size:",mainBox);
    size = new QSpinBox(mainBox);
    size->setMinimum(1);
    size->setValue(1);

    // iterations
    QLabel* iterationsLabel = new QLabel("Iterations:",mainBox);
    iterations = new QSpinBox(mainBox);
    iterations->setValue(1);

    // set Layout
    currentLayout->addWidget(operationLabel);
    currentLayout->addWidget(operationCombo);
    currentLayout->addWidget(elementLabel);
    currentLayout->addWidget(structuringElement);

    //SubLayout
    QGridLayout* horizontal = new QGridLayout(mainBox);
    horizontal->addWidget(sizeLabel,0,0,1,1);
    horizontal->addWidget(iterationsLabel,0,1,1,1);
    horizontal->addWidget(size,1,0,1,1);
    horizontal->addWidget(iterations,1,1,1,1);

    currentLayout->addLayout(horizontal);
    mainBox->setLayout(currentLayout);

    //Connects
    QObject::connect(operationCombo,&QComboBox::currentTextChanged,op,&Operations::onSignalReceived);
    QObject::connect(structuringElement,&QComboBox::currentTextChanged,op,&Operations::onSignalReceived);
    QObject::connect(size,SIGNAL_CAST_INT(&QSpinBox::valueChanged),op,&Operations::onSignalReceived);
    QObject::connect(iterations,SIGNAL_CAST_INT(&QSpinBox::valueChanged),op,&Operations::onSignalReceived);

    //return
    return mainBox;

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
