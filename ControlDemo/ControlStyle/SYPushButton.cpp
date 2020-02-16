//git add pushbutton/sypushbutton.cpp
//git commit -m "pushbutton" pushbutton/sypushbutton.cpp
//git push -u origin master


//http://www.cnblogs.com/emouse/archive/2013/07/14/3189319.html
//http://www.360doc.com/content/11/1122/10/7899729_166398154.shtml
//http://www.cnblogs.com/xj626852095/p/3648119.html
//http://blog.163.com/qimo601@126/blog/static/15822093201432494134937/
//https://my.oschina.net/upday7/blog/109597
//http://www.xuebuyuan.com/1832172.html
//http://blog.csdn.net/Qyee16/article/details/51234794




#include "sypushbutton.h"
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
#include <QString>

SYPushButton::SYPushButton(QWidget *parent)
    : QPushButton(parent)
    , cursorStatus(SY_INIT)
{
}

void SYPushButton::setImages(QString &normalFileName, QString &horverFilenName, QString &pressFileName)
{
    cursorStatus = SY_NORMAL;
    imageName[SY_NORMAL] = normalFileName;
    imageName[SY_HOVER] = horverFilenName;
    imageName[SY_PRESS] = pressFileName;
}

void SYPushButton::enterEvent(QEvent *)
{
    if (cursorStatus == SY_INIT) {
        return;
    }

    cursorStatus = SY_HOVER;
    update();
}

void SYPushButton::leaveEvent(QEvent *)
{
    if (cursorStatus == SY_INIT) {
        return;
    }

    cursorStatus = SY_NORMAL;
    update();
}

void SYPushButton::mousePressEvent(QMouseEvent *event)
{
    if (cursorStatus == SY_INIT) {
        return;
    }

    if (event->button() == Qt::LeftButton)
    {
        cursorStatus = SY_PRESS;
        update();
    }
}

void SYPushButton::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (cursorStatus != SY_INIT) {
            cursorStatus = SY_HOVER;
            update();
        }
        // 鼠标释放的时候激发clicked信号
        if (rect().contains(event->pos())) {
            emit clicked();
        }
    }
}

void SYPushButton::paintEvent(QPaintEvent *event)
{
    if (cursorStatus == SY_INIT) {
        QPushButton::paintEvent(event);
        return;
    }

    QPainter painter(this);
    QPixmap pixmap(imageName[cursorStatus]);
    painter.drawPixmap(rect(), pixmap);
}


