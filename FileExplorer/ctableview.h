#ifndef CTABLEVIEW_H
#define CTABLEVIEW_H

#include <QTableView>
#include <QMessageBox>

class CTableView : public QTableView
{
    Q_OBJECT
public:
    explicit CTableView(QWidget *parent = 0);
    
signals:
    
public slots:
    void directoryChanged(const QString &path);
};

#endif // CTABLEVIEW_H
