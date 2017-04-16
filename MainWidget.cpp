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
    //60 * 14
    //ui->pushButton->setImages(normal, hover, down);
    //ui->pushButton->setImages(":/images/switch_normal.png", ":/images/switch_hover.png", ":/images/switch_down.png");
    pushButtonStyle();
}

void MainWidget::pushButtonStyle()
{
    //Qt Style Sheets Examples
    //normal, hover, pressed, enabled, released, checked可以组合使用
    ui->pushButton->setStyleSheet(
                "QPushButton{background-image:url(:/images/switch_normal.png);color:white;}"
                "QPushButton:hover{background-image:url(:/images/switch_hover.png);color:red;}"
                "QPushButton:pressed{background-image:url(:/images/switch_down.png);color:#00ff00;}");
                //"QPushButton:normal:!enabled { color: red }"
                //"QPushButton:hover:!enabled { color: green }"
                //"QPushButton:pressed:!enabled { color: blue; }");
    ui->pushButton_style->setMinimumSize(48, 48);
    ui->pushButton_style->setMaximumSize(48, 48);
    ui->pushButton_style->setStyleSheet(
                "QPushButton{background-image:url(:/images/crystal_1.png);color:white;}"
                "QPushButton:hover{background-image:url(:/images/crystal_2.png);color:red;}"
                "QPushButton:pressed{background-image:url(:/images/crystal_3.png);color:#00ff00;}");
    //http://www.w3school.com.cn/cssref/index.asp
        //background-repeat:设置是否及如何重复背景图像  http://www.w3school.com.cn/cssref/pr_background-repeat.asp
        //background-color:背景色
        //color:字体颜色
        //background-position:背景图像的开始位置
        //background-image:背景图
        //font-family:字体族
        //border:设置所有的边框属性 上下左右
        //padding:设置所有内边距属性  文字离边框的距离：上下左右
        //text-align:文本对齐方式
        //font-weight:字体粗细
        //font-size:字体大小
    //76 * 76
//    ui->pushButton->setMinimumSize(176, 176);
//    ui->pushButton->setMaximumSize(176, 176);
//    ui->pushButton->setStyleSheet(
//                "QPushButton {color: rgb(255, 255, 255); background-color: rgb(167, 205, 255); border:none; padding: 3px; font-family: \"Verdana\"; font-size: 15px; text-align: center;}"
//                "QPushButton:hover, QPushButton:pressed , QPushButton:checked { background-color: rgb(85, 170, 255); text-align: right; padding-right: 20px; font-weight:100 }"
//                "QPushButton:hover { background-image: url(:/images/appbar.navigate.next.png); background-repeat:no-repeat; background-position: center left;}"
//                "QPushButton:pressed, QPushButton:checked { background-image: url(:/images/appbar.navigate.next.png); background-repeat:no-repeat; background-position: center left;}");

}

void MainWidget::labelStyle()
{

}

