#include "thresholdgray.h"
#include <QVBoxLayout>
#include <QLabel>


// Public
ThresholdGray::ThresholdGray(Function *parent) : Function(parent),
    type( QStringList()
           << "THRESH_BINARY"
           <<  "THRESH_BINARY_INV"
           << "THRESH_TRUNC"
           << "THRESH_TOZERO"
           << "THRESH_TOZERO_INV")
{}

ThresholdGray::~ThresholdGray(){

}

QWidget* ThresholdGray::getLayout(const Operations* connectingInstance){
    mainBox = new QWidget();

    // Set layout
    QVBoxLayout* layout = new QVBoxLayout(mainBox);

    //Items
    //Combo
    QLabel* comboLabel = new QLabel("Select threshold type",mainBox);
    typeCombo = new QComboBox(mainBox);
    typeCombo->addItems(type);

    //Threshold
    QLabel* thresholdLabel = new QLabel("Select threshold (0-255)",mainBox);
    threshold = new QSpinBox(mainBox);
    threshold->setValue(0);
    threshold->setMinimum(0);
    threshold->setMaximum(255);

    // Set up layout
    layout->addWidget(comboLabel);
    layout->addWidget(typeCombo);
    layout->addWidget(thresholdLabel);
    layout->addWidget(threshold);
    mainBox->setLayout(layout);

    //Connect
    connect(typeCombo,&QComboBox::currentTextChanged,connectingInstance,&Operations::onWidgetChanged);
    connect(threshold,SIGNAL_CAST_INT(&QSpinBox::valueChanged),connectingInstance,&Operations::onWidgetChanged);

    return mainBox;
}

cv::Mat ThresholdGray::processImage(cv::Mat image) const{
    int type = getType();
    int threshold = getThreshold();

    if(image.channels() == 3){
        cv::cvtColor(image,image,cv::COLOR_BGR2GRAY);
    }

    cv::threshold(image,image,threshold,255,type);

    return image;


}

// Private

int ThresholdGray::getType() const{
    QString currentType = typeCombo->currentText();
    int returnType;
    int index = type.indexOf(currentType);

    switch(index){

    default:
        return (-1);
        //Err(or

//      "THRESH_BINARY"
    case (0):
        returnType = cv::THRESH_BINARY;
        break;
//      "THRESH_BINARY_INV"
    case (1):
        returnType = cv::THRESH_BINARY_INV;
        break;
//      "THRESH_TRUNC"
    case (2):
        returnType = cv::THRESH_TRUNC;
        break;
//      "THRESH_TOZERO"
    case (3):
        returnType = cv::THRESH_TOZERO;
        break;
//      "THRESH_TOZERO_INV"
    case (4):
        returnType = cv::THRESH_TOZERO_INV;
        break;

    }

    return returnType;

}

int ThresholdGray::getThreshold() const{
    return (threshold->value());

}
