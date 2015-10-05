#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    
    model = new QDirModel(this);
    model->setReadOnly(false);
    
    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    
    ui->treeView->setModel(model);
    
    QModelIndex index = model->index("C:/");
    
    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    ui->treeView->setCurrentIndex(index);
    ui->treeView->resizeColumnToContents(0);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    //  mkdir
    
    QModelIndex index = ui->treeView->currentIndex();
    if (!index.isValid()) return;
    
    QString name = QInputDialog::getText(this, "Name", "Enter a name");
    
    if (name.isEmpty()) return;
    
    model->mkdir(index, name);
}

void Dialog::on_pushButton_2_clicked()
{
    //  delete
    
    QModelIndex index = ui->treeView->currentIndex();
    
    if (!index.isValid()) return;
    
    QString yesno = QInputDialog::getText(this, "Delete?", "Type y to delete");
    
    if (yesno == "y")
    {
        if (model->fileInfo(index).isDir())
        {
            // dir
            model->rmdir(index);
        }
        else
        {
            //file
            model->remove(index);
        }
    }
}
