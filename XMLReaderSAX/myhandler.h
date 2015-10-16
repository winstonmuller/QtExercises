#ifndef MYHANDLER_H
#define MYHANDLER_H

#include <QXmlDefaultHandler>
#include <QString>
#include <QTextStream>
#include <QTextEdit>

class MyHandler : public QXmlDefaultHandler
{

public:
    bool startDocument();
    bool endDocument();

    bool characters(const QString& text);
    
    bool startElement(const QString &namespaceURI
        , const QString &localName
        , const QString &qName
        , const QXmlAttributes &atts);
    bool endElement(const QString &namespaceURI
        , const QString &localName
        , const QString &qName);
    
    void setOutput(QTextEdit* textEdit)
    {
        output = textEdit;
    }

signals:
    
public slots:
private:
    QTextEdit* output;
};

#endif // MYHANDLER_H
