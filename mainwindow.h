#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    bool _displayHandbook=false;//打开精灵手册
    void paintEvent(QPaintEvent*);//重载
    void DrawInterface(QPainter&painter);
    void DrawHandbook(QPainter&painter);
    QLabel* _seer=NULL;
    QLabel* _maker=NULL;

};

#endif // MAINWINDOW_H
