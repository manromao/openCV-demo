#ifndef CVTCOLOR_H
#define CVTCOLOR_H

#include <QObject>
#include <QSpinBox>
#include <QComboBox>
#include <QLayout>
#include <QLabel>

#include "function.h"


class CvtColor : public Function
{
    Q_OBJECT
public:
    explicit CvtColor(Function *parent = 0);
    ~CvtColor();
    QWidget* getLayout(const Operations* connectingInstance);
    cv::Mat processImage(cv::Mat image) const;

private:
    const QStringList operationsList;
    int getOperationCode() const;
    int getChannels() const;

    //Widgets
    QWidget* mainBox;
    QComboBox* operationCombo;
    QSpinBox* dstCn;
};

#endif // CVTCOLOR_H
