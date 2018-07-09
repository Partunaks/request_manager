#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<string.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("requests.sqlite");
    db.open();
    connect(ui->add_b,SIGNAL(clicked(bool)),this,SLOT(AddData()));
    connect(ui->get_b,SIGNAL(clicked(bool)),this,SLOT(GetData()));
    model = new QSqlTableModel(this,db);
    QPixmap pixmap("renault.png");
    QPicture picture("renault.png");
    ui->picture_l->setPixmap(pixmap);
    ui->picture_l->setPicture(picture);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::AddData()
{


    QString requester = ui->requester_l->text();
    QString IPN = ui->ipn_l->text();
    QString description = ui->description_t->toPlainText();
    QString status;
    if(ui->status_box->isChecked())
    {
        status = "Done!";
    }
    else
    {
        status="In progress!";
    }
    QSqlQuery query;
    query.prepare("INSERT INTO request (name,ipn,description,status)"
                  "VALUES (?,?,?,?)");
    query.bindValue(0,requester);
    query.bindValue(1,IPN);
    query.bindValue(2,description);
    query.bindValue(3,status);
    bool qur = false;
    qur= query.exec();
    qDebug()<<qur<<query.lastError()<<"\n"<<query.lastQuery();

}

void MainWindow::GetData()
{
        model->setTable("request");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();
        model->removeColumn(3);
        ui->table_v->setModel(model);
        ui->table_v->resizeColumnsToContents();
        ui->table_v->resizeRowsToContents();

}
