#include "grader.hh"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Grader w;
    w.show();

    return a.exec();
}
