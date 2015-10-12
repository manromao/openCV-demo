#include "function.h"
#include <QWidget>
#include <QDebug>

Function::Function(QObject *parent) : QObject(parent){}

Function::~Function(){
    qDebug() << "Function destructor";
}

QWidget* Function::getLayout(const Operations* ){
    qDebug() << "Function getLayout not overriden...ERROR";
    return (new QWidget());
}

cv::Mat Function::processImage(cv::Mat image) const{
    qDebug() << "Function processImage not overriden...ERROR";
    return cv::Mat(image);
}
