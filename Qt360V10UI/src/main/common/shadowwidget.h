#ifndef SHADOWWIDGET_H
#define SHADOWWIDGET_H

#include <QWidget>
#include <QDialog>

class ShadowWidget : public QDialog
{
    Q_OBJECT
public:
    explicit ShadowWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    //供子类继承a
    virtual void paintEvent(QPaintEvent *event);

private:
    QPoint m_movePoint; //移动的距离a
    bool m_mousePress; //按下鼠标左键a
};

#endif // SHADOWWIDGET_H
