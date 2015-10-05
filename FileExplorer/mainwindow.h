#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QTreeView>
#include <QListView>
#include <QFileSystemModel>
#include <QSplitter>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_treeView_clicked(const QModelIndex &index);
    
private:
    QTreeView* treeView;
    QListView* listView;
    
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
    
};

#endif
