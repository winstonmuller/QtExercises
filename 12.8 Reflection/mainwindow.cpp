#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DoReflectionThings()
{
    m_spinBox = new QSpinBox;
    m_process = new QProcess;
    m_timer = new QTimer;

    //

}
