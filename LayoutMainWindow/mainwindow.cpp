#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    formGroupBox = new QGroupBox(tr("Form layout"));
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("Line 1:")), new QLineEdit);
    layout->addRow(new QLabel(tr("Line 2, long text:")), new QComboBox);
    layout->addRow(new QLabel(tr("Line 3:")), new QSpinBox);
    formGroupBox->setLayout(layout);

    setCentralWidget(formGroupBox);
}


MainWindow::~MainWindow()
{
    
}
