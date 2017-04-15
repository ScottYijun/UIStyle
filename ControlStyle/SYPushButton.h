#ifndef SYPUSHBUTTON_H
#define SYPUSHBUTTON_H

#include <QPushButton>

class SYPushButton: public QPushButton
{
    Q_OBJECT

public:
    explicit SYPushButton(QWidget *parent = 0);
    void setImages(QString &normalFileName, QString &horverFilenName, QString &pressFileName);

protected:
    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *);

private:
    typedef enum {
        SY_INIT, SY_NORMAL, SY_HOVER, SY_PRESS, SY_COUNT
    } Status;
    Status cursorStatus;
    QString imageName[SY_COUNT];
};



#endif // SYPUSHBUTTON_H
