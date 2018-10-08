#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<string.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QString host;
    QString driver;
    //Setup UI
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(1);
    ui->tab->setEnabled(false);

    //Read config from XML
    QFile file("config.xml");
    file.open(QIODevice::ReadOnly);
    QXmlStreamReader xmlReader;
    xmlReader.setDevice(&file);
    while(!xmlReader.atEnd() && !xmlReader.hasError())
    {
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        if(token == QXmlStreamReader::StartDocument)
        {
            continue;
        }
        if(token == QXmlStreamReader::StartElement)
        {
            if(xmlReader.name() == "database")
            {
                continue;
            }
            if(xmlReader.name() == "host")
            {

            }

        }

       }

    //Setup database settings
    qDebug()<<driver;
    qDebug()<<host;
    db=QSqlDatabase::addDatabase(driver);
    db.setHostName(host);

    //Create connection of SIGNALS and SLOTS
    connect(ui->add_b,SIGNAL(clicked(bool)),this,SLOT(AddData()));
    connect(ui->enter_button,SIGNAL(clicked(bool)),this,SLOT(Enter()));

    //Create sqltableModel to show data from DB
    model = new QSqlTableModel(this,db);

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
        //model->removeColumn(3);
        ui->table_v->setModel(model);
        ui->table_v->resizeColumnsToContents();
        ui->table_v->resizeRowsToContents();

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
    ui->tabWidget->setCurrentIndex(0);
    ui->tab->setEnabled(true);
    ui->centralWidget->resize(851,561);
    ui->auth_tab->setEnabled(false);
    }
    else {

       QMessageBox::critical(nullptr,"Error", "Access denied!");
    }
    ui->ipn_t->setText("");
    ui->pass_t->setText("");
}

