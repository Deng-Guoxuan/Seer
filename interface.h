#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>


class Interface : public QMainWindow
{
    Q_OBJECT
public:
    explicit Interface(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);//重载
private:
    void DrawLogin(QPainter&painter);
signals:

public slots:
};

#endif // INTERFACE_H