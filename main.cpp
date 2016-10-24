#include <QCoreApplication>
#include "chardet.h"
#include "big5checker.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<< Chardet().detect("\xa3\x01").c_str();
    return a.exec();
}
