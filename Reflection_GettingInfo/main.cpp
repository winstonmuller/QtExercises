#include <QApplication>
#include <QSpinBox>
#include <QTextStream>
#include <iostream>

void RunReflection(const QApplication &a)
{
    QTextStream cout(stdout);

    QSpinBox* spinBox = new QSpinBox;
    const QMetaObject* metaSpin = spinBox->metaObject();

    cout << "Winston was here" << endl;

    //  Show properties, their values (if QString), and all the method names
    cout << "Retrieving data for the class " << metaSpin->className() << endl;
    cout << metaSpin->methodCount() << endl;

    //  values

    //  Method names

}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RunReflection(a);

    return a.exec();
}
