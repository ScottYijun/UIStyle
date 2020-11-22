#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initView();
    connect(ui->pushButton_openFile, SIGNAL(clicked()), this, SLOT(slotOpenFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initView()
{
    ui->checkBox_dir->setCheckable(true);
    ui->checkBox_file->setCheckable(true);
    ui->checkBox_symlink->setCheckable(true);
    ui->checkBox_readable->setCheckable(true);
    ui->checkBox_writeable->setCheckable(true);
    ui->checkBox_executable->setCheckable(true);
}

void MainWindow::slotOpenFile()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    tr("Open"),
                                                    "../",
                                                    tr("All Files(*.*)"));
    if(filePath.isEmpty())
    {
        QMessageBox::critical(nullptr, "tips", "file path is Empty");
        return;
    }
    else
    {
        ui->lineEdit->setText(filePath);
    }

    QString infoList;
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        infoList += tr("Open file: %1 Successfully\n").arg(filePath);
        file.close();
        QFileInfo info(filePath);
        infoList += tr("fileName: %1\n").arg(info.fileName());
        infoList += tr("author: %1\n").arg(info.owner());
        infoList += tr("ownerId: %1\n").arg(info.ownerId());
        infoList += tr("group: %1\n").arg(info.group());
        infoList += tr("groupId: %1\n").arg(info.groupId());
        infoList += tr("fileSize: %1 KB\n").arg(info.size());
        infoList += tr("createdTime: %1\n").arg(info.birthTime().toString("yyyy-MM-dd hh:mm:ss"));
        infoList += tr("modifiedTime: %1\n").arg(info.lastModified().toString("yyyy-MM-dd hh:mm:ss"));
        infoList += tr("lastReadTime: %1\n").arg(info.lastRead().toString("yyyy-MM-dd hh:mm:ss"));
        ui->textEdit->setText(infoList);


        //ÊôÐÔ
        bool isDir = info.isDir();
        bool isFile = info.isFile();
        bool isSymLink = info.isSymLink();
        bool isReadable = info.isReadable();
        bool isWriteable = info.isWritable();
        bool isExecutable = info.isExecutable();

        ui->checkBox_dir->setChecked(isDir);
        ui->checkBox_file->setChecked(isFile);
        ui->checkBox_symlink->setChecked(isSymLink);
        ui->checkBox_readable->setChecked(isReadable);
        ui->checkBox_writeable->setChecked(isWriteable);
        ui->checkBox_executable->setChecked(isExecutable);
    }
    else
    {
        QMessageBox::critical(nullptr, "tips", "open file error");
    }
}



