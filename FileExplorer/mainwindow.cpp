#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QSplitter* vsplitter = new QSplitter(Qt::Vertical);
    
    //  QLineEdit and QPushButton
    QSplitter* hsplitter = new QSplitter(Qt::Horizontal);
    upButton = new QPushButton;
    txtAddress = new QLineEdit;
    
    upButton->setText("UP");
    
    hsplitter->addWidget(upButton);
    hsplitter->addWidget(txtAddress);
    
    connect(upButton, SIGNAL(clicked()),
        this, SLOT(on_upButton_clicked()));
    
    vsplitter->addWidget(hsplitter);
    
    //  QTreeView
    QString sPath = "C:/";
    dirmodel = new QFileSystemModel;
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(sPath);
    
    treeView = new QTreeView(this);
    treeView->setModel(dirmodel);
    
    vsplitter->addWidget(treeView);
    
    connect(treeView, SIGNAL(clicked(const QModelIndex& )), 
            this, SLOT(on_treeView_clicked(QModelIndex)) );
    
    //  QListView
    filemodel = new QFileSystemModel;
    
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    filemodel->setRootPath(sPath);
    
    listView = new QListView;
    listView->setModel(filemodel);
    
    vsplitter->addWidget(listView);
    
    //  Populate Form
    setCentralWidget(vsplitter);
    
    this->resize(800, 800);
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
    
    QModelIndex filesIndex = filemodel->setRootPath(sPath);
    listView->setRootIndex(filesIndex);
    
    QString currentPath = dirmodel->fileInfo(index).absoluteFilePath();
    txtAddress->setText(currentPath);
}

void MainWindow::on_upButton_clicked()
{
    if (treeView->selectionModel()->selectedIndexes().count() > 0)
    {
        QModelIndex index = treeView->selectionModel()->selectedIndexes().first();
        
        treeView->scrollTo(index.parent());
        treeView->setCurrentIndex(index.parent());
        
        emit on_treeView_clicked(index.parent()); // simulate the user clicking on the parent node
    }
}

MainWindow::~MainWindow()
{
    
}
