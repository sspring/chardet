#include <QCoreApplication>
#include "chardet.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<< Chardet().detect("\xe5\x91\xa8\xe4\xb8\x87\xe6\x98\xa5").c_str();
    return a.exec();
}
