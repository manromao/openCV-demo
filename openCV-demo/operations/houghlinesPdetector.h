#ifndef HOUGHLINES_H
#define HOUGHLINES_H

#include "function.h"

#include <QObject>
#include <QSpinBox>
#include <QComboBox>
#include <QLayout>
#include <QLabel>

class HoughLinesDetector : public Function
{
public:
    HoughLinesDetector(Function* parent = 0);
    ~HoughLinesDetector();
    virtual QWidget* getLayout(const Operations* connectingInstance);
    virtual cv::Mat processImage(cv::Mat image) const;

private:

    QWidget* mainBox;

    QSpinBox* rho;
    QSpinBox* theta;
    QSpinBox* threshold;
    QSpinBox* minLength;
    QSpinBox* maxGap;

    int getRho()const;
    int getTheta() const;
    int getThreshold() const;
    int getLength() const;
    int getGap() const;


};

#endif // HOUGHLINES_H
