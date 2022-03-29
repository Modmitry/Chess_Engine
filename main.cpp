#include "chess.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CHESS w;
    w.show();

    return a.exec();
}
