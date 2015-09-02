#ifndef CUSTOMTAB_H
#define CUSTOMTAB_H

#include <QTabWidget>
#include <QString>
#include <QGroupBox>

#include "operations.h"
#include <opencv2/opencv.hpp>

class CustomTab : public QTabWidget
{
    Q_OBJECT

public:
    CustomTab(QTabWidget* parent = 0);
    ~CustomTab();
    void modifyTab(QString* newOperation);
    void setTabText(QString* text);
    QString  getTabText();
    void doOperation(cv::Mat image);

private:
    QString tabText;
    QString lastTabText;
    Operations op;

    QTabWidget* getParent();
    void setOperationBox(const QString* operation);

    void deleteOperationBox();

    QWidget* getMainBox();


    void GenerateVectorData(const QString* operation);

signals:
    void onTabNameChanged();
    void newOperationEvent();

public slots:
    void onComboClicked(QString text);
    void onDataChanged();
    void onNewOperation(cv::Mat image);
};

#endif // CUSTOMTAB_H
