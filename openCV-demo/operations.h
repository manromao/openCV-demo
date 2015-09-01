#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <QStringList>
#include <QLabel>
#include <QLayout>
#include <QComboBox>
#include <QSpinBox>

#include <opencv2/opencv.hpp>
class Operations;
class Function;
#include "operations/function.h"

#define SIGNAL_CAST static_cast<void (QSpinBox::*)(int)>


class Operations: public QObject
{
    Q_OBJECT
public:
    const QStringList operationList;
    const QString childName = "operationLayout";
    Function* selectedOperation;

    Operations();
    QWidget* getLayouts(const QString* operation);
    void switchOperations(const QString operation, cv::Mat image) const;

 public slots:
    void onSignalReceived();
signals:
    void performOperationEvent();
};

#endif // OPERATIONS_H
