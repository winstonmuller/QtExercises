#include <QApplication>
#include <QSpinBox>
#include <QTextStream>
#include "reflector.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextStream cout(stdout);
    QSpinBox* spinBox = new QSpinBox;

    Reflector ref;
    ref.Reflect(cout, spinBox);

    return a.exec();
}
