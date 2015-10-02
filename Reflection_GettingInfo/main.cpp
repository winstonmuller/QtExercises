#include <QApplication>
#include <QSpinBox>
#include <QTextStream>
#include <iostream>
#include <QVariant>
#include <QMetaObject>
#include <QMetaProperty>

void RunReflection(const QApplication &a)
{
    QTextStream cout(stdout);

    QSpinBox* spinBox = new QSpinBox;
    const QMetaObject* metaSpin = spinBox->metaObject();

    cout << QString("Retrieving data for the class %1").arg(metaSpin->className()) << endl;
    cout << QString("Number of methods: %1").arg(metaSpin->methodCount()) << endl;

    //  Show properties, their values (if QString), and all the method names
    for (int i = 0; i < metaSpin->propertyCount(); i++)
    {
        const QMetaProperty qpm = metaSpin->property(i);
        cout << QString("Property : %1").arg(qpm.name()) << endl;

        //  values that can be converted to a string
        QVariant value = spinBox->property(qpm.name());
        if (value.canConvert(QVariant::String))
        {
            cout << QString("The Property %1 has a string value of %2").arg(qpm.name()).arg(value.toString()) << endl;
        }
    }

    //  Method names
    for (int c = 0; c < metaSpin->methodCount(); c++)
    {
        const QMetaMethod qmm = metaSpin->method(c);
        cout << QString("Method Number %1 is %2 ").arg(QString::number(c)).arg(QString(qmm.name())) << endl;
    }

    cout << "Reflection Complete" << endl;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RunReflection(a);

    return a.exec();
}
