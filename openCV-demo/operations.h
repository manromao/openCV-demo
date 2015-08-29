#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <QStringList>
#include <QLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>

#include <opencv2/opencv.hpp>



class Operations
{
public:
    const  QStringList operationList;
    Operations();
    QVBoxLayout* getLayouts(const QString* operation) const;
    void switchOperations(const QString* operation) const;

private:
    QVBoxLayout* operationMorph() const;

};

#endif // OPERATIONS_H
