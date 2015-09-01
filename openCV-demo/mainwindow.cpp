#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QFileDialog>
#include <QDir>
#include <opencv2/opencv.hpp>
#include <QMainWindow>


using namespace std;
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createNewTab();
}

MainWindow::~MainWindow()
{

    delete ui;
}

// Public:

// Build an empty Tab into TabWidget
void MainWindow::createNewTab(){
    CustomTab* tab = new CustomTab(ui->tabWidget);
    ui->tabWidget->addTab(tab, tab->getTabText());
    connect(tab, &CustomTab::onTabNameChanged, this, &MainWindow::onTabNameChanged);
}

void MainWindow::clearTab(const CustomTab* tab){
}

void MainWindow::deleteTab(CustomTab* tab){
    delete tab;
}

// private slots:

void MainWindow::onTabNameChanged(){
    int index = ui->tabWidget->currentIndex();
    CustomTab* tab =  qobject_cast<CustomTab*>(ui->tabWidget->widget(index));
    ui->tabWidget->setTabText(index,tab->getTabText());


}

void MainWindow::onPushButtonClicked()
{
    QString QfileName = QFileDialog::getOpenFileName();
    std::string fileName = QfileName.toUtf8().constData();
    currentPicture = cv::imread(fileName);
    cv::imshow("Image display", currentPicture);
}

void MainWindow::onTabClose(){}


