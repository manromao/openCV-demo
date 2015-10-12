#ifndef THRESHOLDGRAY_H
#define THRESHOLDGRAY_H

#include <QObject>
#include <QStringList>
#include <QComboBox>
#include <QSpinBox>
#include "function.h"

class ThresholdGray : public Function
{
    Q_OBJECT
public:
    explicit ThresholdGray(Function* parent = 0);
    ~ThresholdGray();
    virtual QWidget* getLayout(const Operations* connectingInstance);
    virtual cv::Mat processImage(cv::Mat image) const;

private:
    QStringList type;

    QWidget* mainBox;
    QComboBox* typeCombo;
    QSpinBox* threshold;

    int getType() const;
    int getThreshold() const;


};

#endif // THRESHOLDGRAY_H
