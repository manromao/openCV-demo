#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createNewTab();
    void operationMorph();
    void operationColor();

private slots:
    void on_pushButton_clicked();
    void onComboClicked();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
