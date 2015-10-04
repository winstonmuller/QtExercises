#ifndef CFILESYSTEMMODEL_H
#define CFILESYSTEMMODEL_H

#include <QFileSystemModel>

class CFileSystemModel : public QFileSystemModel
{
    Q_OBJECT
public:
    explicit CFileSystemModel(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // CFILESYSTEMMODEL_H
