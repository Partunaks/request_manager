#ifndef NWINDOW_H
#define NWINDOW_H

#include <QMainWindow>
#include <QWidget>

class nWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit nWindow(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // NWINDOW_H