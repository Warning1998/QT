#虽然但是，也不知道为啥，但是在模拟器上可以运行的程序，在实机上却没法运行。具体的问题以后再说吧

****

```
#include "mainwindow.h"

#include <QApplication>
#include "qdebug.h"
#include <QUrl>
#include <QDir>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*-------------------------------------*/
    /* 创建photo文件夹*/
    QDir *photo = new QDir;
    QUrl url("file:///storage/emulated/0/Leo");
    QString path = url.toLocalFile();  //获取到的路径
    bool exist = photo->exists(path);
    qDebug()<<"photo"<<exist;

    if(exist)
    {
        QMessageBox::information(0,"eeee","ttttt");
    } else
    {
        //创建photo文件夹
        photo->mkdir(path);
        QMessageBox::information(0,"eeee","create leo");
    }
    /*-------------------------------------*/
    MainWindow w;
    w.show();
    return a.exec();
}

```
