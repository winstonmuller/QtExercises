#include "reflector.h"

Reflector::Reflector()
{
}

void Reflector::Reflect(QTextStream& cout, const QObject* widget)
{
    const QMetaObject* metaObj = widget->metaObject();

    cout << QString("Retrieving data for the class %1").arg(metaObj->className()) << endl;
    cout << QString("Number of methods: %1").arg(metaObj->methodCount()) << endl;

    //  Show properties, their values (if String)
    for (int i = 0; i < metaObj->propertyCount(); i++)
    {
        const QMetaProperty qpm = metaObj->property(i);
        cout << QString("Property : %1").arg(qpm.name()) << endl;

        //  values that can be converted to a string
        QVariant value = widget->property(qpm.name());
        if (value.canConvert(QVariant::String))
        {
            cout << QString("The Property %1 has a string value of %2").arg(qpm.name()).arg(value.toString()) << endl;
        }
    }

    //  Method names
    for (int c = 0; c < metaObj->methodCount(); c++)
    {
        const QMetaMethod qmm = metaObj->method(c);
        cout << QString("Method Number %1 is %2 ").arg(QString::number(c)).arg(QString(qmm.name())) << endl;
    }

    cout << "Reflection Complete" << endl;
    cout << endl;
}
