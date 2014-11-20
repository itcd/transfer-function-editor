#include "transferfunctioneditor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TransferFunctionEditor w;
    w.show();

    return a.exec();
}
