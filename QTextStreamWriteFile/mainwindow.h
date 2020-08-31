#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initConnect();

signals:
    void signalWirteFileEnd(int ret);

public slots:
    void slotWirteFile();
    void slotReadFile();
    void slotWirteFileEnd(int ret);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
