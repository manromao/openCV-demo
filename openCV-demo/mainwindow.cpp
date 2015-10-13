#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QFileDialog>
#include <QDir>
#include <opencv2/opencv.hpp>
#include <QMainWindow>

using namespace std;
using namespace cv;

#define DECIMALS 2

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->tabWidget, &QTabWidget::tabCloseRequested,
            this,&MainWindow::onTabClose);
    connect(ui->tabWidget, &QTabWidget::tabBarClicked,
            this,&MainWindow::onTabWidgetClicked);

    tabCreator();

    setFileManagement();




}

MainWindow::~MainWindow()
{
    delete ui;
}

// Private:

// Build an empty Tab into TabWidget
void MainWindow::createNewTab(){
    CustomTab* tab = new CustomTab(ui->tabWidget);
    int insertIndex = ui->tabWidget->count() -1;
    ui->tabWidget->insertTab(insertIndex,tab, tab->getTabText());
    connect(tab, &CustomTab::onTabNameChanged, this, &MainWindow::onTabNameChanged);
    connect(tab,&CustomTab::newOperationEvent,this, &MainWindow::newOperationSlot);
}

void MainWindow::deleteTab(CustomTab* tab){
    delete tab;
}

void MainWindow::updateTabName(){
    int index = ui->tabWidget->currentIndex();
    CustomTab* tab =  qobject_cast<CustomTab*>(ui->tabWidget->widget(index));
    ui->tabWidget->setTabText(index,tab->getTabText());
}

void MainWindow::showImage(){
    cv::namedWindow("Image display", WINDOW_NORMAL);
    if (!currentPicture.empty()) cv::imshow("Image display", currentPicture);
    else std::cout << "MainWindow::showImage: Trying to show empty picture" << std::endl;
}

void MainWindow::tabCreator(){
    // Add the tab
    QTabWidget* tab = new QTabWidget(this);
    ui->tabWidget->addTab(tab,"+");

    // Remove close button
    ui->tabWidget->tabBar()->tabButton(0, QTabBar::RightSide)->resize(0, 0);
    ui->tabWidget->tabBar()->setTabTextColor(0,Qt::black);

}

cv::Mat MainWindow::callAllOperations(){
    originalPicture.copyTo(currentPicture);
    startChrono();
    CustomTab* tab;
    for (int index = 0; index < ui->tabWidget->count()-1; ++index) {
        tab = qobject_cast<CustomTab*>(ui->tabWidget->widget(index));
        tab->doOperation(currentPicture).copyTo(currentPicture);
    }
    double elapsedTime = stopChrono();
    setTimer(elapsedTime);
    return (currentPicture);
}

void MainWindow::setTimer(double timeElapsed){
    QString timeElapsedString = QString::number(timeElapsed,'f', DECIMALS);
    ui->timerText->setText(timeElapsedString);
}

void MainWindow::startChrono(){
    chrono.start();
}

double MainWindow::stopChrono(){
    return(chrono.restart()/1000.00);
}

void MainWindow::setFileManagement(){
    // Connect all buttons
    connect(ui->PlayButton,&QPushButton::clicked,&myFileManager,&FileManagement::playPics);
    connect(ui->PauseButton,&QPushButton::clicked,&myFileManager,&FileManagement::pausePics);
    connect(ui->forwardButton,&QPushButton::clicked,&myFileManager,&FileManagement::showNextPic);
    connect(ui->backButton,&QPushButton::clicked,&myFileManager,&FileManagement::showPreviousPic);
    connect(ui->loadButton,&QPushButton::clicked,&myFileManager,&FileManagement::loadFile);

    // Connect file changed

    connect(&myFileManager,&FileManagement::oncurrentPictureChanged,this,&MainWindow::changedOriginalPicture);



}

// private slots:

void MainWindow::onTabNameChanged(){
    updateTabName();
}

void MainWindow::newOperationSlot(){   
    if (!currentPicture.empty()){
        currentPicture = callAllOperations();
        showImage();
    }
    else {
        if (originalPicture.empty()){
            std::cout << "Warning! No image loaded" << std::endl;
        }
        else{
            currentPicture = originalPicture.clone();
            newOperationSlot();
        }

    }
}

void MainWindow::onPushButtonClicked(){
    QString QfileName = QFileDialog::getOpenFileName();
    std::string fileName = QfileName.toUtf8().constData();
    originalPicture = cv::imread(fileName,CV_LOAD_IMAGE_COLOR);
    originalPicture.copyTo(currentPicture);
    showImage();
}

void MainWindow::onTabClose(int index){
    CustomTab* tab = qobject_cast<CustomTab*>(ui->tabWidget->widget(index));
    deleteTab(tab);
    newOperationSlot();
}

void MainWindow::onTabWidgetClicked(int index){
    // If last element clicked
    if (index == ui->tabWidget->count()-1){
        createNewTab();
    }
}

void MainWindow::changedOriginalPicture(){
    // Update the image data (path and matrix)
    QString QfileName = myFileManager.currentPicturePath;
    std::string fileName = QfileName.toUtf8().constData();
    originalPicture = cv::imread(fileName,CV_LOAD_IMAGE_COLOR);
    originalPicture.copyTo(currentPicture);

    // redo operations
    callAllOperations();

    showImage();


}


