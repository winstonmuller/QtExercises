#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
   QGroupBox* formGroupBox;
};

#endif // MAINWINDOW_H
