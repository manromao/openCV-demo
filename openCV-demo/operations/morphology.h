#ifndef MORPHOLOGY_H
#define MORPHOLOGY_H

#include <QObject>
#include <QSpinBox>
#include <QComboBox>
#include <QLayout>
#include <QLabel>
#include "function.h"


class Morphology: public Function
{
    Q_OBJECT
public:
    explicit Morphology(Function *parent = 0);
    ~Morphology();
    virtual QWidget* getLayout(const Operations* connectingInstance);
    virtual cv::Mat processImage(cv::Mat image) const;

private:
    const QStringList operationsList;    
    int getOperationCode() const;
    int getStructuringElement() const;
    int getSize() const;
    int getIterations() const;

    //Widgets
    QWidget* mainBox;
    QComboBox* operationCombo;
    QComboBox* structuringElement;
    QSpinBox* size;
    QSpinBox* iterations;

};

#endif // MORPHOLOGY_H
