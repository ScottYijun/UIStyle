#include "MainWidget.h"
#include "ui_MainWidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    initImages();
}

MainWidget::~MainWidget()
{
    delete ui;
}



void MainWidget::initImages()
{
    QString normal = ":/images/switch_normal.png";
    QString hover =  ":/images/switch_hover.png";
    QString down = ":/images/switch_down.png";
    ui->pushButton->setImages(normal, hover, down);
    //ui->pushButton->setImages(":/images/switch_normal.png", ":/images/switch_hover.png", ":/images/switch_down.png");
}


