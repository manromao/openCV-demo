#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "string.h"
#include "customtab.h"
#include "operations.h"
#include <opencv2/opencv.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::string currentPicturePath;
    cv::Mat currentPicture;
    cv::Mat originalPicture;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    void createNewTab();
    void clearTab(const CustomTab* tab);
    void deleteTab(CustomTab* tab);
    void updateTabName();
    void showImage();

signals:
    void newOperationEvent(cv::Mat image);

protected slots:
    void onTabNameChanged();
    void newOperationSlot();
    void onPushButtonClicked();
    void onTabClose();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
