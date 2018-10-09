#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QDebug>
#include<QtSql/QSqlError>
#include<QStandardItemModel>
#include<QStandardItem>
#include<QMessageBox>
#include<QXmlStreamReader>
#include<QFile>
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
    QSqlDatabase db;
    //QStandardItemModel *model;
    QStandardItem *item;
    QStringList horizontalHeader;
    QStringList verticalHeader;
    quint16 row=0;
    quint16 col=0;
    QSqlTableModel *model;
public slots:
    void AddData();
    void GetData();
    void Enter();
    //void read_conf(QString host,QString driver);
private slots:

};

#endif // MAINWINDOW_H
