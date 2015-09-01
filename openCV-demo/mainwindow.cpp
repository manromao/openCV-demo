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
    connect(ui->pushButton,&QPushButton::clicked,
            this, &MainWindow::onPushButtonClicked);
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
    connect(tab,&CustomTab::newOperationEvent,this, &MainWindow::newOperationSlot);
    connect(this,&MainWindow::newOperationEvent,tab,&CustomTab::onNewOperation);

}

void MainWindow::deleteTab(CustomTab* tab){
    delete tab;
}

// private slots:

void MainWindow::onTabNameChanged(){
    updateTabName();
}

void MainWindow::newOperationSlot(){
    originalPicture.copyTo(currentPicture);
    emit newOperationEvent(currentPicture);
    showImage();
}



void MainWindow::onPushButtonClicked()
{
    QString QfileName = QFileDialog::getOpenFileName();
    std::string fileName = QfileName.toUtf8().constData();
    originalPicture = cv::imread(fileName);
    originalPicture.copyTo(currentPicture);
    showImage();
}

void MainWindow::onTabClose(){}


void MainWindow::updateTabName(){
    int index = ui->tabWidget->currentIndex();
    CustomTab* tab =  qobject_cast<CustomTab*>(ui->tabWidget->widget(index));
    ui->tabWidget->setTabText(index,tab->getTabText());
}

void MainWindow::showImage(){
    cv::imshow("Image display", currentPicture);
}
