#ifndef TopLeftNavigation_H
#define TopLeftNavigation_H

#include <QWidget>

class QToolButton;

namespace Ui {
class TopLeftNavigation;
}

class TopLeftNavigation : public QWidget
{
    Q_OBJECT

public:
    explicit TopLeftNavigation(QWidget *parent = 0);
    ~TopLeftNavigation();

private:
    Ui::TopLeftNavigation *ui;

    QList<int> pixCharMain;
    QList<QToolButton *> btnsMain;

    QList<int> pixCharConfig;
    QList<QToolButton *> btnsConfig;

private slots:
    void initForm();
    void buttonClick();
    void initLeftMain();
    void initLeftConfig();
    void leftMainClick();
    void leftConfigClick();

private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();
};

#endif // TopLeftNavigation_H
