#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QSplitter* vsplitter = new QSplitter(Qt::Vertical);

    QString sPath = "C:/";
    dirmodel = new QFileSystemModel;
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(sPath);
    
    treeView = new QTreeView(this);
    treeView->setModel(dirmodel);
    
    vsplitter->addWidget(treeView);
    
    filemodel = new QFileSystemModel;
    
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    filemodel->setRootPath(sPath);
    
    listView = new QListView;
    listView->setModel(filemodel);
    
    vsplitter->addWidget(listView);
    
    setCentralWidget(vsplitter);
    
    this->resize(800, 800);
    
    connect(treeView,SIGNAL(clicked(const QModelIndex& ) ), 
        this,
        SLOT(on_treeView_clicked(QModelIndex)) );
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
        
    QModelIndex filesIndex = filemodel->setRootPath(sPath);
    listView->setRootIndex(filesIndex);
}

MainWindow::~MainWindow()
{

}
