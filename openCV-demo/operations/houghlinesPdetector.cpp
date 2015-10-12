#include "houghlinesPdetector.h"

HoughLinesDetector::HoughLinesDetector(Function* parent) : Function(parent)
{
    std::cout << "HoughLines constructor called" << std::endl;

}

HoughLinesDetector::~HoughLinesDetector(){
    std::cout << "HoughLines destructor called" << std::endl;
}

QWidget* HoughLinesDetector::getLayout(const Operations* connectingInstance){
    mainBox = new QWidget();

    QGridLayout* currentLayout = new QGridLayout(mainBox);

    // rho
    QLabel* rhoLabel = new QLabel("Distance rho", mainBox);
    rho = new QSpinBox(mainBox);
    rho->setValue(1);

    // theta
    QLabel* thetaLabel = new QLabel("Angle theta", mainBox);
    theta = new QSpinBox(mainBox);
    theta->setValue(1);
    theta->setMaximum(360);


    // threshold
    QLabel* thresholdLabel = new QLabel("Threshold", mainBox);
    threshold = new QSpinBox(mainBox);
    threshold->setValue(100);
    threshold->setMaximum(1000);

    //min Length
    QLabel* lengthLabel = new QLabel("Min Length", mainBox);
    minLength = new QSpinBox(mainBox);
    minLength->setValue(0);
    minLength->setMaximum(1000);

    //Max Gap
    QLabel* gapLabel = new QLabel("Max Gap", mainBox);
    maxGap = new QSpinBox(mainBox);
    maxGap->setValue(0);
    maxGap->setMaximum(1000);

    //Add to Layout
    currentLayout->addWidget(rhoLabel,0,0,1,1);
    currentLayout->addWidget(rho,1,0,1,1);
    currentLayout->addWidget(thetaLabel,0,1,1,1);
    currentLayout->addWidget(theta,1,1,1,1);
    currentLayout->addWidget(thresholdLabel,2,0,1,2);
    currentLayout->addWidget(threshold,3,0,1,2);
    currentLayout->addWidget(lengthLabel,4,0,1,1);
    currentLayout->addWidget(minLength,5,0,1,1);
    currentLayout->addWidget(gapLabel,4,1,1,1);
    currentLayout->addWidget(maxGap,5,1,1,1);

    mainBox->setLayout(currentLayout);

    // Connects
    connect(rho,SIGNAL_CAST_INT(&QSpinBox::valueChanged),connectingInstance,&Operations::onWidgetChanged);
    connect(theta,SIGNAL_CAST_INT(&QSpinBox::valueChanged),connectingInstance,&Operations::onWidgetChanged);
    connect(threshold,SIGNAL_CAST_INT(&QSpinBox::valueChanged),connectingInstance,&Operations::onWidgetChanged);
    connect(minLength,SIGNAL_CAST_INT(&QSpinBox::valueChanged),connectingInstance,&Operations::onWidgetChanged);
    connect(maxGap,SIGNAL_CAST_INT(&QSpinBox::valueChanged),connectingInstance,&Operations::onWidgetChanged);

    return (mainBox);
}

cv::Mat HoughLinesDetector::processImage(cv::Mat image) const{
    int inputRho        = getRho();
    int inputTheta      = getTheta();
    int inputThreshold  = getThreshold();
    int inputLength          = getLength();
    int inputGap             = getGap();
    cv::Mat src;

    src = image.clone();
    if (src.channels() == 3){
        cv::cvtColor(src,src,cv::COLOR_BGR2GRAY);
    }

    std::vector<cv::Vec4i> lines;
    cv::HoughLinesP(src, lines, inputRho, inputTheta*(CV_PI/180), inputThreshold,inputLength, inputGap);

    if (image.channels() == 1){
        cv::cvtColor(image,image,cv::COLOR_GRAY2BGR);
    }

    for( uint i = 0; i < lines.size(); i++ )
    {
        cv::Vec4i l = lines[i];
        cv::line( image, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]),
                cv::Scalar(0,0,255), 3, cv::LINE_AA);
    }

    return (image);
}

int HoughLinesDetector::getRho()const{
    return (rho->value());
}

int HoughLinesDetector::getTheta() const{
    return(theta->value());
}

int HoughLinesDetector::getThreshold() const{
    return(threshold->value());
}

int HoughLinesDetector::getLength() const{
    return(minLength->value());
}

int HoughLinesDetector::getGap() const{
    return(maxGap->value());
}

