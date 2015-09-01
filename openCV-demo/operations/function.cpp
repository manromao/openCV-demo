#include "function.h"

Function::Function(QObject *parent) : QObject(parent)
{

}

QWidget* Function::getLayout(const Operations* op){
    std::cout << "should never reach" << std::endl;
    return new QWidget();
}
cv::Mat Function::processImage(cv::Mat image) const{
    std::cout << "should never reach" << std::endl;
    return cv::Mat();
}
