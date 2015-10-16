#include "mainwindow.h"
#include <QFormLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    formGroupBox = new QGroupBox(tr("Form Layout"));
    QFormLayout *layout = new QFormLayout;
    
    filePath = new QLineEdit;
    //  My default dir TODO: File open dialog
    filePath->setText(tr(
        "C:\\cos\\MyCode\\XMLReaderSAX\\samplefile.xml"
        ));
    layout->addRow(new QLabel(tr("Input File:")), filePath);
    
    QPushButton* btnGo = new QPushButton("GO");
    connect(btnGo, SIGNAL(clicked()),
        this, SLOT(on_upButton_clicked()));
    layout->addRow(btnGo);
    
    txtOutput = new QTextEdit;
    txtOutput->setMinimumSize(500, 400);
    layout->addRow(txtOutput);

    formGroupBox->setLayout(layout);
    setCentralWidget(formGroupBox);
}

void MainWindow::on_upButton_clicked()
{
    MyHandler handler; //  declare a handler
    //  For now, set the handler to output to a textbox, not the best
    //  way to do this but works for demo purposes.
    handler.setOutput(txtOutput);
    QXmlSimpleReader reader;     //  declare an XML reader
    reader.setContentHandler(&handler); //  Set the reader's handler
    
    //  Declare the file according to the 
    QFile xmlFile(filePath->text());
    
    QXmlInputSource source(&xmlFile);
    reader.parse(source);
}

MainWindow::~MainWindow()
{
    
}
