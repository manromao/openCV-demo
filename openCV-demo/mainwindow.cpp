#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDir>
#include <opencv2/opencv.hpp>
#include <QMainWindow>
#include <QLabel>
#include <QLayout>
#include <QApplication>
#include <QComboBox>
#include <ccombobox.h>


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
    QTabWidget* tab = new QTabWidget();

    //Set Visual stuff
    QLabel* operationsLabel = new QLabel("Function:",tab);
    QFrame* frame = new QFrame(tab);
    frame->setFrameShape(QFrame::HLine);
    QVBoxLayout* layout = new QVBoxLayout(tab);    // Layout

    // Combo list
    CComboBox* combo  = new CComboBox(tab);
    combo->addItems(op.operationList);
    connect(combo, SIGNAL(currentTextChanged(QString)),SLOT(onComboClicked()));

    // Construct the layout
    layout->addWidget(operationsLabel);
    layout->addWidget(combo);
    layout->addWidget(frame);
    layout->addStretch();

    //send layout and tab to display in ui
    tab->setLayout(layout);
    ui->tabWidget->addTab(tab, "New Tab");
}
void MainWindow::clearTab(const QWidget* tab){
    QList<QWidget*>widgetList = tab->findChildren<QWidget*>();
    assert(!widgetList.isEmpty());
}

// private slots:
void MainWindow::onComboClicked(){}
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
void MainWindow::on_pushButton_clicked()
{
    QString QfileName = QFileDialog::getOpenFileName();
    std::string fileName = QfileName.toUtf8().constData();
    currentPicture = cv::imread(fileName);
    cv::imshow("Image display", currentPicture);
}




