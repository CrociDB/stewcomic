#include <QApplication>
#include "stewcomic.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    stewcomic w;
    w.show();
    
    return a.exec();
}
