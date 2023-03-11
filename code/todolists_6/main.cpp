#include "todolists.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToDoLists w;
    w.show();

    return a.exec();
}
