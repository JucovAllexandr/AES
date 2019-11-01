#include "widget.h"

#include <QApplication>
#include <aes.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Aes aes;
    aes.encrypt("buy me some potato chips please", "keys are boring1");
    Widget w;
    w.show();
    return a.exec();
}
