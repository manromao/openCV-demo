#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <opencv2/opencv.hpp>
#include <QVector>
#include <QMainWindow>
#include <QLabel>
#include <QLayout>
#include <QFormLayout>
#include <QApplication>
#include <QDebug>
#include <QComboBox>
#include <QSpinBox>
#include <ccombobox.h>


using namespace std;
using namespace cv;


// Global variables
cv::Mat input;



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

void MainWindow::operationMorph()
{
    QVBoxLayout* currentLayout = ui->tabWidget->currentWidget()->findChild<QVBoxLayout*>();
    // Elements for the new layout
    QLabel* operationLabel = new QLabel("Operation:");
    QComboBox* operation = new QComboBox();
        operation->addItem("MORPH_OPEN");
        operation->addItem("MORPH_CLOSE");
        operation->addItem("MORPH_DILATE");
        operation->addItem("MORPH_ERODE");

    QLabel* elementLabel = new QLabel("Structuring Element:");
    QComboBox* structuringElement = new QComboBox();
    structuringElement->addItem("MORPH_RECT");

    QLabel* sizeLabel = new QLabel("Size:");
    QSpinBox* size = new QSpinBox();
    size->setValue(0);
    QLabel* iterationsLabel = new QLabel("Iterations:");
    QSpinBox* iterations = new QSpinBox();
    iterations->setValue(0);


    currentLayout->addWidget(operationLabel);
    currentLayout->addWidget(operation);
    currentLayout->addWidget(elementLabel);
    currentLayout->addWidget(structuringElement);

    QGridLayout* horizontal = new QGridLayout();
    horizontal->addWidget(sizeLabel,0,0,1,1);
    horizontal->addWidget(iterationsLabel,0,1,1,1);
    horizontal->addWidget(size,1,0,1,1);
    horizontal->addWidget(iterations,1,1,1,1);

    currentLayout->addLayout(horizontal);
    currentLayout->addStretch();


}

// Destroy current layout on tab to have a clean one
void clearTab(QWidget* tab){
    QList<QWidget*>widgetList = tab->findChildren<QWidget*>();
    if (widgetList.isEmpty()) cout << "Empty Tab"<< endl;

}

void MainWindow::onComboClicked(){
    // Set Tab text to currentCombo selection
    int currentIndex = ui->tabWidget->currentIndex();
    //
    QList<CComboBox *> combos= ui->tabWidget->currentWidget()->findChildren<CComboBox *>();
    if (combos.isEmpty()) cout << "No combo box asshole" <<endl;
    else
    {
        CComboBox * currentCombo= combos[0];
        QString previousText = currentCombo->GetPreviousText();
        if (previousText != currentCombo->currentText())
        {

            clearTab(ui->tabWidget->currentWidget());
            ui->tabWidget->setTabText(currentIndex, currentCombo->currentText());

            //Check wether to create a new tab (-1 because current index starts at 0)
            if (currentIndex == (ui->tabWidget->count()-1)) { //If we are at the last tab
                createNewTab();
            }

            else{
                //do nothing
            }
            // Switch which operation to perform
            switch(currentCombo->currentIndex())
            {
            case (0):
                operationMorph();
                break;
            default:
                cout << "Default" << endl;
                break;
            }
        }
    }
}


void MainWindow::createNewTab(){
    // Build Tab
    QTabWidget* tab = new QTabWidget();  //tab that will be created every time
    // elements
           // ComboBox for all the operations(Deleted with scope)
    QLabel* operationsLabel = new QLabel("Function:");
    QFrame* frame = new QFrame();
    frame->setFrameShape(QFrame::HLine);
    QVBoxLayout* layout = new QVBoxLayout(tab);    // Layout
    CComboBox* combo  = new CComboBox();
    // Combo list
        combo->addItem("Morphology");
        combo->addItem("Canny");
    // Construct the tab
    layout->addWidget(operationsLabel);
    layout->addWidget(combo);
    layout->addWidget(frame);
    layout->addStretch();
    tab->setLayout(layout);
    connect(combo, SIGNAL(activated(int)),SLOT(onComboClicked()));
    ui->tabWidget->addTab(tab, "New Tab");
}

void MainWindow::on_pushButton_clicked()
{
    QString QfileName = QFileDialog::getOpenFileName();
    std::string fileName = QfileName.toUtf8().constData();
    input = cv::imread(fileName);
    cv::imshow("Image display", input);
}




