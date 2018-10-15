#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<string.h>
#include<config.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QString host;
    QString driver;
    //Setup UI
    ui->setupUi(this);
    ui->widget->setStyleSheet("background-color: #fff677");
    ui->ipn_t->setStyleSheet("background-color: white");
    ui->pass_t->setStyleSheet("background-color: white");
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setEnabled(false);

    //reading configuration
    read_conf(host,driver);

    //Setup database settings
    qDebug()<<driver;
    qDebug()<<host;
    //USER DB
    db=QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    //Create connection of SIGNALS and SLOTS
    connect(ui->add_b,SIGNAL(clicked(bool)),this,SLOT(AddData()));
    connect(ui->enter_button,SIGNAL(clicked(bool)),this,SLOT(Enter()));

    //Create sqltableModel to show data from DB
    model = new QSqlTableModel(this,db);
    model_store = new QSqlTableModel(this,db);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::AddData()
{

    db.open();
    QString requester = ui->requester_l->text();
    QString IPN = ui->ipn_l->text();
    QString description = ui->description_t->toPlainText();
    QString status;
    QDate date = ui->calendarWidget->selectedDate();

    if(ui->status_box->isChecked())
    {
        status = "Done!";
    }
    else
    {
        status="In progress!";
    }


    QSqlQuery query;
    query.prepare("INSERT INTO request (name,ipn,description,status,date)"
                  "VALUES (?,?,?,?,?)");
    query.bindValue(0,requester);
    query.bindValue(1,IPN);
    query.bindValue(2,description);
    query.bindValue(3,status);
    query.bindValue(4,date);
    bool qur = false;
    qur= query.exec();
    QMessageBox msgbx;
    if(qur == true)
    {
        QMessageBox::information(nullptr,"Info", "Request added succesfully!");
    }
    else
    {
       QMessageBox::warning(nullptr,"Warning", "Can't add request!");
    }

    qDebug()<<qur<<query.lastError()<<"\n"<<query.lastQuery();

    //Clear fields
    ui->requester_l->setText("");
    ui->ipn_l->setText("");
    ui->description_t->setText("");
    MainWindow::GetData();

}

void MainWindow::GetData()
{
        model->setTable("request");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();
        ui->table_v->setModel(model);
        ui->table_v->resizeColumnsToContents();
        ui->table_v->resizeRowsToContents();




}

void MainWindow::Refresh_store()
{
    db.close();
    db.setDatabaseName("store");
    db.open();
    model_store->setTable("computers");
    model_store->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_store->select();
    ui->tv_store->setModel(model_store);
    model_store->removeColumn(0);
    //ui->tv_store->resizeColumnsToContents();
    ui->tv_store->resizeRowsToContents();
    ui->tv_store->setColumnWidth(1,150);
    ui->tv_store->setColumnWidth(2,150);
    db.setDatabaseName(ui->ipn_t->text());

}

void MainWindow::Enter()
{
    QString login = ui->ipn_t->text();
    QString pass = ui->pass_t->text();
    db.setDatabaseName(login);
    db.setUserName(login);
    db.setPassword(pass);
    if(db.open() == true)
    {
    MainWindow::GetData();
    ui->widget->hide();
    ui->tabWidget->setEnabled(true);
    }
    else {


       QMessageBox::critical(nullptr,"Error", "Access denied!");
    }

    ui->pass_t->setText("");
    Refresh_store();
}

