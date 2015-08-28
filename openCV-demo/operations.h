#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <QStringList>
#include <QLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>

#include <opencv2/opencv.hpp>



class Operations
{
public:
    const  QStringList operationList;
    cv::Mat image;
    QVBoxLayout* opLayout;

    Operations();
    QVBoxLayout* switchOperations() const;
private:

    QVBoxLayout* operationMorph() const;

};

#endif // OPERATIONS_H
