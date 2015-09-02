#ifndef FUNCTION_H
#define FUNCTION_H

#include <QObject>
#include "operations.h"

#define SIGNAL_CAST_INT static_cast<void (QSpinBox::*)(int)>
#define SIGNAL_CAST_BOOL static_cast<void (QSpinBox::*)(bool)>

class Function : public QObject
{
    Q_OBJECT
public:
    explicit Function(QObject *parent = 0);
    ~Function();
    virtual QWidget* getLayout(const Operations* connectingInstance);
    virtual cv::Mat processImage(cv::Mat image) const;
};

#endif // FUNCTION_H
