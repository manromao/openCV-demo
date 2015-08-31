#ifndef CUSTOMTAB_H
#define CUSTOMTAB_H

#include <QTabWidget>
#include <QString>
#include <QGroupBox>

#include "operations.h"
#include <opencv2/opencv.hpp>

class CustomTab : public QTabWidget
{
public:


    CustomTab(QTabWidget* parent = 0);

    ~CustomTab();
    void modifyTab(QString* newOperation);

    void setTabText(QString* text);
    QString  getTabText();

private:
    QString tabText;
    QString lastTabText;


    Operations op;
    void setOperationBox(const QString* operation);
    void doOperation(const QString* operation,const cv::Mat &image);    
    void deleteOperationBox();

    QWidget* getMainBox();


    void GenerateVectorData(const QString* operation);

signals:
    void onWidgetChanged();

public slots:
    void onComboClicked(QString text);

};

#endif // CUSTOMTAB_H
