#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <QWidget>
#include <iostream>
#include <QVariant>
#include <QMetaObject>
#include <QTextStream>
#include <QMetaProperty>

/*
 *  The reflector class takes a QWidget, and outputs information about it.
*/

class Reflector
{
public:
    Reflector();
    void Reflect(QTextStream& cout, const QObject* widget);
};

#endif // REFLECTOR_H
