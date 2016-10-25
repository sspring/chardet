#include <QCoreApplication>
#include "chardet.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<detect("\x8e\xfc").c_str();
    return a.exec();
}
