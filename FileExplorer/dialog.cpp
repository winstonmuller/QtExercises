#include "dialog.h"


Dialog::Dialog(QObject *parent) :
    QObject(parent)
{
    //ui->setupUi(this);
    
    QString sPath = "C:/";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(sPath);
    
    treeView->setModel(dirmodel);
    
    filemodel = new QFileSystemModel(this);
    
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    filemodel->setRootPath(sPath);
    
    listView->setModel(filemodel);
}

//Dialog::~Dialog()
//{
//    delete ui;
//}

void Dialog::on_treeView_clicked(const QModelIndex &index)
{
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
        
    QModelIndex filesIndex = filemodel->setRootPath(sPath);
    listView->setRootIndex(filesIndex);
}
