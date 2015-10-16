#include "myhandler.h"

//QTextStream output(stdout);

bool MyHandler::characters(const QString& text) {
    QString t = text;
    output->append(t.remove('\n'));
    return true;
}


bool MyHandler::startDocument()
{
    return true;
}

bool MyHandler::endDocument()
{
    return true;
}

bool MyHandler::startElement(const QString &namespaceURI
    , const QString &localName
    , const QString &qName
    , const QXmlAttributes &atts)
{
    output->append(localName);

    return true;
}

bool MyHandler::endElement(const QString &namespaceURI
    , const QString &localName
    , const QString &qName)
{
    return true;
}
