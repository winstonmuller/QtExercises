#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_treeView_clicked(const QModelIndex &index);
    void on_upButton_clicked();
    
private:
    QTreeView* treeView;
    QListView* listView;
    
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
    
    QPushButton *upButton;
    QLineEdit *txtAddress;
    
};

#endif
