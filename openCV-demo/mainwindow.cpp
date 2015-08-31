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
    CustomTab *tab = new CustomTab(ui->tabWidget);
    ui->tabWidget->addTab(tab, tab->getTabText());

}
void MainWindow::clearTab(const CustomTab* tab){


}

void deleteTab(CustomTab* tab){
    delete tab;
}

// private slots:
//void MainWindow::onComboClicked(){}
//void MainWindow::onComboClicked(){
//    // Set Tab text to currentCombo selection
//    int currentIndex = ui->tabWidget->currentIndex();

//    // Get reference to the comboBox selected

//    QList<CComboBox*> combos= ui->tabWidget->currentWidget()->findChildren<CComboBox*>();
//    if (combos.isEmpty()) cout << "No combo box asshole" <<endl;
//    else{
//        CComboBox * currentCombo= combos[0];
//        // new operation selected
//        if (currentCombo->GetPreviousText() != currentCombo->currentText()){
//            clearTab(ui->tabWidget->currentWidget()); // clear the element in the tab

//            ui->tabWidget->setTabText(currentIndex, currentCombo->currentText());

//            //Check wether to create a new tab (-1 because current index starts at 0)
//            if (currentIndex == (ui->tabWidget->count()-1)) { //If we are at the last tab
//                createNewTab();
//            }
//          }
//    }
//}

void MainWindow::onPushButtonClicked()
{
    QString QfileName = QFileDialog::getOpenFileName();
    std::string fileName = QfileName.toUtf8().constData();
    currentPicture = cv::imread(fileName);
    cv::imshow("Image display", currentPicture);
}

void MainWindow::onTabClose(){}


