/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionExit;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTabWidget *tabWidget;
    QLineEdit *timerText;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *loadButton;
    QPushButton *backButton;
    QPushButton *PlayButton;
    QPushButton *forwardButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(531, 603);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 0, 85, 27));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 50, 481, 381));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(true);
        timerText = new QLineEdit(centralWidget);
        timerText->setObjectName(QStringLiteral("timerText"));
        timerText->setEnabled(false);
        timerText->setGeometry(QRect(10, 440, 41, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 450, 67, 17));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(190, 480, 236, 44));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        loadButton = new QPushButton(horizontalLayoutWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loadButton->sizePolicy().hasHeightForWidth());
        loadButton->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../Desktop/Icons/Button-Add-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        loadButton->setIcon(icon);
        loadButton->setIconSize(QSize(32, 32));
        loadButton->setFlat(true);

        horizontalLayout->addWidget(loadButton);

        backButton = new QPushButton(horizontalLayoutWidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        sizePolicy.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../Desktop/Icons/Button-Rewind-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon1);
        backButton->setIconSize(QSize(32, 32));
        backButton->setFlat(true);

        horizontalLayout->addWidget(backButton);

        PlayButton = new QPushButton(horizontalLayoutWidget);
        PlayButton->setObjectName(QStringLiteral("PlayButton"));
        sizePolicy.setHeightForWidth(PlayButton->sizePolicy().hasHeightForWidth());
        PlayButton->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../../Desktop/Icons/Button-Play-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        PlayButton->setIcon(icon2);
        PlayButton->setIconSize(QSize(32, 32));
        PlayButton->setFlat(true);

        horizontalLayout->addWidget(PlayButton);

        forwardButton = new QPushButton(horizontalLayoutWidget);
        forwardButton->setObjectName(QStringLiteral("forwardButton"));
        sizePolicy.setHeightForWidth(forwardButton->sizePolicy().hasHeightForWidth());
        forwardButton->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../../Desktop/Icons/Button-Fast-Forward-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        forwardButton->setIcon(icon3);
        forwardButton->setIconSize(QSize(32, 32));
        forwardButton->setFlat(true);

        horizontalLayout->addWidget(forwardButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 531, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Load", 0));
        timerText->setText(QApplication::translate("MainWindow", "0 ", 0));
        label->setText(QApplication::translate("MainWindow", "seconds", 0));
        loadButton->setText(QString());
        backButton->setText(QString());
        PlayButton->setText(QString());
        forwardButton->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
