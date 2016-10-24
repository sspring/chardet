#include <QCoreApplication>
#include "chardet.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<< detect("\xa3\x01").c_str();
    return a.exec();
}
