#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QProcess>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void DoReflectionThings();

private:
    Ui::MainWindow *ui;
    //  These probably dont need to be member variables, leave them here for now
    QSpinBox* m_spinBox;
    QProcess* m_process;
    QTimer* m_timer;
};

#endif // MAINWINDOW_H
