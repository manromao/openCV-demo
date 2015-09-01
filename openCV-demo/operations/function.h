#ifndef FUNCTION_H
#define FUNCTION_H

#include <QObject>
#include "operations.h"

class Function : public QObject
{
    Q_OBJECT
public:
    explicit Function(QObject *parent = 0);
    virtual QWidget* getLayout(const Operations* op);
    virtual cv::Mat processImage(cv::Mat image) const;
};

#endif // FUNCTION_H
