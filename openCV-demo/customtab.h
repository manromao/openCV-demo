#ifndef CUSTOMTAB_H
#define CUSTOMTAB_H

#include <QTabWidget>
#include <QString>

#include "operations.h"
#include <opencv2/opencv.hpp>

class CustomTab : public QTabWidget
{
public:


    CustomTab(QWidget* parent = 0);
    CustomTab(const CustomTab&);
    ~CustomTab();
    void modifyTab() const;
    void changeLayout(const QString* operation);

    void setTabText(QString text);
    QString  getTabText();

private:
    QString tabText;
    QString lastTabText;

    Operations op;
    void changeOperationLayout(const QString* operation);
    void doOperation(const QString* operation,const cv::Mat &image);
    void GenerateVectorData(const QString* operation);



signals:
    void onWidgetChanged();

public slots:
    void onComboClicked(QString text);

};

#endif // CUSTOMTAB_H
