#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QFile>
#include <QMessageBox>
#include <QXmlSimpleReader>
#include "myhandler.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void on_upButton_clicked();
    
private:
    QGroupBox* formGroupBox;
    QLineEdit* filePath;
    QTextEdit* txtOutput;
};

#endif // MAINWINDOW_H
