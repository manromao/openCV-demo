#ifndef MORPHOLOGY_H
#define MORPHOLOGY_H

#include "function.h"
#include <QObject>

class Morphology: public Function
{
    Q_OBJECT
public:
    explicit Morphology(Function *parent = 0);
    virtual QWidget* getLayout(const Operations* op);
    virtual cv::Mat processImage(cv::Mat image) const;
private:
    const QStringList operationsList;

    //Widgets
    QWidget* mainBox;
    QComboBox* operationCombo;
    QComboBox* structuringElement;
    QSpinBox* size;
    QSpinBox* iterations;

    int getOperationCode() const;
    int getStructuringElement() const;
    int getSize() const;
    int getIterations() const;
};

#endif // MORPHOLOGY_H
