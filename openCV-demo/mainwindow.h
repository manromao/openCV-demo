#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "string.h"
#include "customtab.h"
#include "operations.h"
#include <ccombobox.h>
#include <opencv2/opencv.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Operations op;
    std::string currentPicturePath;
    cv::Mat currentPicture;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createNewTab();
    void clearTab(const CustomTab* tab);
    void deleteTab(CustomTab* tab);

protected slots:
    void onTabNameChanged();
    void onPushButtonClicked();
    void onTabClose();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
