#include "view.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create an instance of View and show:
    View w;
    w.show();

    // Start the QT execution loop:
    return a.exec();
}
