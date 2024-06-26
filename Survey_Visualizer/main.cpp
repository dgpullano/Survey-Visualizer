#include "view.h"
#include "controller.h"
#include "model.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create an instance of Model, View, and Controller:
    Model model;
    View view;
    Controller controller(&view, &model);

    // Show the view:
    view.show();

    // Start the QT execution loop:
    return app.exec();
}
