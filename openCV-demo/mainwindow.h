#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QTabWidget>
#include "string.h"
#include "customtab.h"
#include "operations.h"
#include <opencv2/opencv.hpp>
#include "filemanagement.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::string picturePath;
    cv::Mat currentPicture;
    cv::Mat originalPicture;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QElapsedTimer chrono;
    FileManagement myFileManager;

    void createNewTab();
    void clearTab(const CustomTab* tab);
    void deleteTab(CustomTab* tab);
    void updateTabName();
    void showImage();
    void tabCreator();
    cv::Mat callAllOperations();
    void startChrono();
    double stopChrono();
    void setTimer(double timeElapsed);
    void setFileManagement();


private slots:
    void onTabNameChanged();
    void newOperationSlot();
    void onPushButtonClicked();
    void onTabClose(int index);
    void onTabWidgetClicked(int index);
    void changedOriginalPicture();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
