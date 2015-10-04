#include <QtWidgets>
#include <QtGui>
#include <QFileSystemModel>
//start id=main
#include "createModel.h"
#include "cfilesystemmodel.h"
#include "ctableview.h"

int main( int argc, char** argv ) {
    QApplication app( argc, argv );
    
    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath("C:\\");
    
    QSplitter vsplitter(Qt::Vertical);
    
    CTableView* table = new CTableView;
    QTreeView tree;
    
    table->setToolTip("QTableView");
    tree.setToolTip("QTreeView");
    
    table->setModel( model );
    table->setColumnWidth(0, 200);                      /* Widen first column of table. */
    table->setColumnWidth(1, 150);
    
    tree.setModel( model );	                           /* Share the same model. */
    tree.header()->resizeSection(0, 200);
    tree.header()->resizeSection(1, 150);              /* Widen the second column of the table. */
    
    table->setSelectionModel( tree.selectionModel() );  /* Common selection model. */
    table->setSelectionBehavior( QAbstractItemView::SelectRows );
    table->setSelectionMode( QAbstractItemView::SingleSelection );
    
    tree.setSelectionModel( table->selectionModel());
    
/*
QObject::connect(&maskbb, SIGNAL( bbChanged(unsigned int) ),
                &valuebb, SLOT( enableBits(unsigned int) ));
*/

//    QObject::connect(model, SIGNAL(directoryLoaded(QString &path)), table, SLOT(directoryChanged(QString &path)));

    QObject::connect(model, SIGNAL(directoryLoaded(QString)), table, SLOT(directoryChanged(QString)));

    
    vsplitter.addWidget ( &tree );
    vsplitter.addWidget( table );
    
    vsplitter.setGeometry(300, 300, 500, 500);
    vsplitter.setWindowTitle("Multiple Views - Editable Model");
    
    vsplitter.show();
    
    return app.exec();
}

