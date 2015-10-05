#ifndef DIALOG_H
#define DIALOG_H

#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>

namespace Ui {
class Dialog;
}

class Dialog : public QObject
{
    Q_OBJECT
    
public:
    explicit Dialog(QObject *parent = 0);
    
private slots:
    void on_treeView_clicked(const QModelIndex &index);
    
private:
    QTreeView* treeView;
    QListView* listView;
    
    
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
    
};

#endif // DIALOG_H
