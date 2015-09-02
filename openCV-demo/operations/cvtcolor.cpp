#include "cvtcolor.h"
#include <QDebug>
// Public
CvtColor::CvtColor(Function *parent) : Function(parent),
    operationsList(QStringList()
                   << "COLOR_RGB2GRAY"
                   << "COLOR_GRAY2RGB"
                   << "COLOR_RGB2HSV"
                   << "COLOR_HSV2RGB"){}

CvtColor::~CvtColor(){
    qDebug() << "CvtColor destructor";
}

QWidget* CvtColor::getLayout(const Operations *op){

    QWidget* opWidget = new QWidget();

    // Layout Set-up
    QVBoxLayout* currentLayout = new QVBoxLayout(opWidget);

    //Item set-up
    // Color codes
    QLabel* conversionCode = new QLabel("Code:",opWidget);
    operationCombo = new QComboBox(opWidget);
    operationCombo->addItems(operationsList);

    //dstCn
    QLabel* dstCnLabel = new QLabel("Number of channels(0 for auto):",opWidget);
    dstCn = new QSpinBox(opWidget);
    dstCn->setValue(0);

    // Build layout
    currentLayout -> addWidget(conversionCode);
    currentLayout -> addWidget(operationCombo);
    currentLayout -> addWidget(dstCnLabel);
    currentLayout -> addWidget(dstCn);
    opWidget->setLayout(currentLayout);

    // Connects
    connect(operationCombo,&QComboBox::currentTextChanged,op,&Operations::onSignalReceived);
    connect(dstCn,SIGNAL_CAST_INT(&QSpinBox::valueChanged),op,&Operations::onSignalReceived);

    //return
    return opWidget;
}

cv::Mat CvtColor::processImage(cv::Mat image) const{

    int numberChannels = getChannels();
    int code = getOperationCode();

    cv::cvtColor(image,image,code,numberChannels);

    return image;
}

//Private
int CvtColor::getOperationCode() const {

    QString operation = operationCombo->currentText();
    int index = operationsList.indexOf(operation);
    int operationCode;

    switch(index){
    //     "COLOR_RGB2GRAY"
    case 0:
        operationCode = cv::COLOR_BGR2GRAY;
        break;
        //     "COLOR_GRAY2RGB"
    case 1:
        operationCode = cv::COLOR_GRAY2BGR;
        break;
        //     "COLOR_RGB2HSV"
    case 2:
        operationCode = cv::COLOR_BGR2HSV;
        break;
        //     "COLOR_HSV2RGB"
    case 3:
        operationCode = cv::COLOR_HSV2BGR;
        break;
    default:
        operationCode = 0;
        break;
    }

    return operationCode;
}

int CvtColor::getChannels() const{

    return (dstCn->value());
}
