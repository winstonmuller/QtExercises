#include <QtWidgets>
#include <QtGui>
#include <QFileSystemModel>
#include <QLineEdit>

void Clicked()
{

}

int main( int argc, char** argv ) {
    QApplication app( argc, argv );
    
    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath("C:/");
    
    QSplitter vsplitter(Qt::Vertical);
    QSplitter hsplitter(Qt::Horizontal);
    
//    CTableView* table = new CTableView;
    QTreeView tree;
    
    tree.setToolTip("QTreeView");
    //table->setToolTip("QTableView");
    
//    table->setModel( model );
//    table->setColumnWidth(0, 200);                      /* Widen first column of table. */
//    table->setColumnWidth(1, 150);
    
    tree.setModel( model );	                           /* Share the same model. */
    tree.header()->resizeSection(0, 200);
    tree.header()->resizeSection(1, 150);              /* Widen the second column of the table. */
    
//    table->setSelectionModel( tree.selectionModel() );  /* Common selection model. */
//    table->setSelectionBehavior( QAbstractItemView::SelectRows );
//    table->setSelectionMode( QAbstractItemView::SingleSelection );
    
    //tree.setSelectionModel( table->selectionModel());
    
//    QObject::connect(model, SIGNAL(directoryLoaded(QString)), table, SLOT(directoryChanged(QString)));
    
//    //  activated(const QModelIndex & index)
//    QObject::connect(&tree, SIGNAL(activated(QModelIndex)), table, SLOT(activated(QModelIndex)));
//    QObject::connect(&tree, SIGNAL(clicked(QModelIndex)), table, SLOT(activated(QModelIndex)));
//    QObject::connect(&tree, SIGNAL(doubleClicked(QModelIndex)), table, SLOT(activated(QModelIndex)));
//    QObject::connect(&tree, SIGNAL(pressed(QModelIndex)), table, SLOT(activated(QModelIndex)));
    
    //CPushButton* button = new CPushButton;
    //button->setText("UP");
    //hsplitter.addWidget(button);
    
    
    //QLineEdit* lineedit = new QLineEdit;
    //lineedit->setText("How are you today?");
    //hsplitter.addWidget(lineedit);
    
    //vsplitter.addWidget(&hsplitter);
    vsplitter.addWidget ( &tree );
    //vsplitter.addWidget( table );
    
    vsplitter.setGeometry(300, 300, 500, 500);
    vsplitter.setWindowTitle("FileExplorer");
    
    vsplitter.show();
    
    return app.exec();
}

