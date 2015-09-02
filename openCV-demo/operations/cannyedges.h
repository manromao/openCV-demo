#ifndef CANNYEDGES_H
#define CANNYEDGES_H

#include <QSpinBox>
#include <QCheckBox>
#include <QLayout>
#include <QLabel>


#include "function.h"


class CannyEdges : public Function
{
    Q_OBJECT
public:
    explicit CannyEdges(Function *parent = 0);
    ~CannyEdges();
    QWidget* getLayout(const Operations* connectingInstance);
    cv::Mat processImage(cv::Mat image) const;

private:
    QWidget* mainBox;
    QSpinBox* upThreshold;
    QSpinBox* lowThreshold;
    QSpinBox* apertureSize;
    QCheckBox* useL2;

    int getUpThreshold() const;
    int getLowThreshold() const;
    int getApertureSize() const;
    bool getUseL2() const;

};

#endif // CANNYEDGES_H
