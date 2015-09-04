#include "cannyedges.h"
#include <QDebug>
CannyEdges::CannyEdges(Function *parent): Function(parent){}

CannyEdges::~CannyEdges(){
    qDebug() << "Canny edges destructor";
}

QWidget* CannyEdges::getLayout(const Operations* op){

    mainBox = new QWidget();

    // Elements:
    // Upper threshold
    QLabel* upLabel = new QLabel("Upper threshold", mainBox);
    upThreshold = new QSpinBox(mainBox);
    upThreshold->setValue(3);

    //Lower threshold
    QLabel* lowLabel = new QLabel("Lower threshold", mainBox );
    lowThreshold = new QSpinBox(mainBox);
    lowThreshold->setValue(1);

    //Aperture size
    QLabel* apertureLabel = new QLabel("Aperture Size", mainBox);
    apertureSize = new QSpinBox(mainBox);
    apertureSize->setSingleStep(2);
    apertureSize->setMinimum(3);
    apertureSize->setMaximum(7);
    apertureSize->setValue(3);

    //L2
    useL2 =  new QCheckBox(mainBox);
    useL2->setText("Use L2 Gradient");

    //Set Layout
    QGridLayout* layout = new QGridLayout(mainBox);
    layout->addWidget(upLabel,0,0);
    layout->addWidget(upThreshold,1,0);

    layout->addWidget(lowLabel,0,1);
    layout->addWidget(lowThreshold,1,1);

    layout->addWidget(apertureLabel,2,0);
    layout->addWidget(apertureSize,3,0);

    layout->addWidget(useL2,3,1,1,1,Qt::AlignCenter);

    // Connects
    connect(upThreshold, SIGNAL_CAST_INT(&QSpinBox::valueChanged),op,&Operations::onSignalReceived);
    connect(lowThreshold, SIGNAL_CAST_INT(&QSpinBox::valueChanged),op,&Operations::onSignalReceived);
    connect(apertureSize, SIGNAL_CAST_INT(&QSpinBox::valueChanged),op,&Operations::onSignalReceived);
    connect(useL2, (&QCheckBox::stateChanged),op,&Operations::onSignalReceived);

    return mainBox;
}

cv::Mat CannyEdges::processImage(cv::Mat image) const{
    double up = getUpThreshold();
    double low = getLowThreshold();
    int aperture = getApertureSize();
    bool L2 = getUseL2();
    cv::cvtColor(image,image,cv::COLOR_RGB2GRAY);
    cv::Canny(image,image,up,low,aperture,L2);

    return image;
}

// Private
int CannyEdges::getUpThreshold() const{
    return (upThreshold->value());
}

int CannyEdges::getLowThreshold() const{
    return (lowThreshold->value());
}

int CannyEdges::getApertureSize() const{
    // Aperture Size must be an ODD number
    if (apertureSize->value()%2 == 0)
        return (apertureSize->value()-1);
    else
        return (apertureSize->value());
}

bool CannyEdges::getUseL2() const{
    return (useL2->isChecked());
}
