#include <QCoreApplication>
#include "chardet.h"
#include <QDebug>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CheckerBase::get_checker("iso2022_jp")->detect("zhou");
    return a.exec();
}
