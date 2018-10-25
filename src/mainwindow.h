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
#include<config.h>
#include<thread>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
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
    QSqlTableModel *model_store;
public slots:
    void AddData();
    void GetData();
    void Enter();
    void Refresh_store();
    void Given();
    void Imaged();
    void Delete_row();
    //void read_conf(QString host,QString driver);
private slots:

    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
