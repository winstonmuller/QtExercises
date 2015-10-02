#include <QApplication>
#include <QSpinBox>
#include <QTextStream>
#include <QProcess>
#include <QTimer>
#include "reflector.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextStream cout(stdout);

    Reflector ref;

    QSpinBox* spinBox = new QSpinBox;
    ref.Reflect(cout, spinBox);

    QProcess* proc = new QProcess;
    ref.Reflect(cout, proc);

    QTimer* timer = new QTimer;
    ref.Reflect(cout, timer);

    return a.exec();
}
