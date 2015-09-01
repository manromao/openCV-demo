#ifndef CVTCOLOR_H
#define CVTCOLOR_H


#include "function.h"
#include <QObject>

class CvtColor : public Function
{
    Q_OBJECT
public:
    explicit CvtColor(Function *parent = 0);
    QWidget* getLayout(const Operations* op);
    cv::Mat processImage(cv::Mat image) const;
private:
    QWidget* mainBox;
    QComboBox* operationCombo;
    QSpinBox* dstCn;

    const QStringList operationsList;

    int getOperationCode() const;
    int getChannels() const;


};

#endif // CVTCOLOR_H
