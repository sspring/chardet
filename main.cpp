#include <QCoreApplication>
#include "chardet.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<check("utf-8","\xe6\xb5\x8b\xe8\xaf\x95");
    return a.exec();
}
