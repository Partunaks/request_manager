//#include<mainwindow.h>
#include<config.h>

/*void xmlparser(QString &host,QString &driver)
{
    QFile* file = new QFile("conf.xml");
    file->open(QIODevice::ReadOnly | QIODevice::Text);
    QXmlStreamReader xml(file);

    while (!xml.atEnd() && !xml.hasError())
    {

        qDebug()<<xml.name();
    }
}*/
void Settings(QString &host,QString &driver)
{
    QSettings *settings = new QSettings("settings.conf",QSettings::NativeFormat);
    host=settings->value("database/host").toString();
    driver=settings->value("database/driver").toString();


}
