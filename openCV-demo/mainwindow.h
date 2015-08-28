#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "string.h"
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


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createNewTab();
    void clearTab(const QWidget* tab);


private slots:
    void on_pushButton_clicked();
    void onComboClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
