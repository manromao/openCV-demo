#ifndef THRESHOLDGRAY_H
#define THRESHOLDGRAY_H

#include <QObject>
#include <QStringList>
#include <QComboBox>
#include <QSpinBox>
#include "function.h"

class thresholdGray : public Function
{
    Q_OBJECT
public:
    explicit thresholdGray(Function* parent = 0);
    ~thresholdGray();
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
