#include "function.h"
#include <QWidget>
#include <QDebug>

Function::Function(QObject *parent) : QObject(parent){}

Function::~Function(){
    qDebug() << "Function destructor";
}

QWidget* Function::getLayout(const Operations* ){
    return (new QWidget());
}

cv::Mat Function::processImage(cv::Mat image) const{
    return cv::Mat(image);
}
