#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <QStringList>
#include <QLabel>
#include <QLayout>
#include <QComboBox>
#include <QSpinBox>

#include <opencv2/opencv.hpp>




class Operations
{
public:
    const QStringList operationList;
    const QString childName = "operationLayout";
    Operations();
    QWidget* getLayouts(const QString* operation) const;
    void switchOperations(const QString* operation) const;

private:
    QWidget* operationMorph() const;
    QWidget* operationColor() const;

};

#endif // OPERATIONS_H
