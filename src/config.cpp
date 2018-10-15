//#include<mainwindow.h>
#include<config.h>


void read_conf(QString &host,QString &driver)
{
    QFile file("conf.xml");
    if (file.open(QIODevice::ReadOnly))
      {
        size_t linenum = 1;

        QTextStream s(&file);
        QString line;

        while(!file.atEnd())
        {
            line = s.readLine();
            if(line.at(0) == "#")
            {
                continue;
            }
            if(linenum == 2)
            {
                host = line;
            }
            else if(linenum == 4)
            {
                driver = line;
            }
            linenum++;
            qDebug()<<line;
        }
        file.close();
      }

}

