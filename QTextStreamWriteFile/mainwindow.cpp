#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initConnect()
{
    connect(ui->pushButton_writeFile, SIGNAL(clicked()), this, SLOT(slotWirteFile()));
    connect(ui->pushButton_readFile, SIGNAL(clicked()), this, SLOT(slotReadFile()));
    connect(this, SIGNAL(signalWirteFileEnd(int)), this, SLOT(slotWirteFileEnd(int)));
}

void MainWindow::slotWirteFile()
{
    QString strFilePath = "../QTextStreamWriteFile/write.html";
    QFile file(strFilePath);
    //��ʽ�� AppendΪ׷�ӣ� WriteOnlyֻд�� ReadOnlyֻ��,Truncate��ʾ���� ��ԭ�ļ�������գ�
    //����ڹ����ļ���û��write.html�ļ�����ô���򽫴������ļ��������ڣ���ԭ�ļ�������գ�
    if(!file.open(QIODevice::WriteOnly |QIODevice::Truncate| QIODevice::Text))
    //if(!file.open(QFile::WriteOnly |QFile::Truncate))
    {
        QMessageBox::critical(nullptr, "tips", "create file error");
        return;
    }

    QTextStream out(&file);
    //������д��html�ļ���
    QString temp = "";
    temp.append("<!DOCTYPE html>\n");
    temp.append("<html lang='en'>\n");

    temp.append("<head>\n");
    temp.append("<meta charset='utf-8'>\n");
    temp.append("<title>QTextStream example</title>");
    temp.append("</head>\n");

    temp.append("<body>\n");
    temp.append("<h1 align=center> Hello World</h1>\n");
    temp.append("</body>\r\n");
    temp.append("</html>\r\n");

    out.setCodec("UTF-8");
    out << temp << endl;
    qDebug() << "temp=======================" << temp;
    out.flush();
    //ע��д�뷽ʽ��ѡ��ע��д���Ĺرղ�����
    file.close();

    emit signalWirteFileEnd(39);
}

void MainWindow::slotReadFile()
{
    QString path = QFileDialog::getOpenFileName(this, "open", "../");
    if(path.isEmpty())
    {
        QMessageBox::critical(nullptr, "tips", "not select file");
        return;
    }

    QFile file;
    file.setFileName(path);
    bool isOpen = file.open(QIODevice::ReadOnly);
    if(isOpen)
    {
        QTextStream stream(&file);
        //ָ��UTF-8����
        stream.setCodec("UTF-8");
        QString str = stream.readAll();
        qDebug() << "str=======================" << str;
        ui->textEdit->setText(str);
    }
    else
    {
        QMessageBox::critical(nullptr, "tips", "open file error");
    }
}

void MainWindow::slotWirteFileEnd(int ret)
{
    qDebug() << "ret=======================" << ret;
}
