#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <opencv2/opencv.hpp>
class Operations;
class Function;
#include "operations/function.h"

class Operations: public QObject
{
    Q_OBJECT
public:
    const QStringList operationList;
    const QString childName = "operationLayout";
    Function* selectedOperation;

    Operations();
    ~Operations();
    QWidget* getLayouts(const QString* operation);
    cv::Mat switchOperations(cv::Mat image) const;

 public slots:
    void onSignalReceived();
signals:
    void performOperationEvent();
};

#endif // OPERATIONS_H
