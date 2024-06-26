#ifndef CONTROLLER_H
#define CONTROLLER_H

// Include necessary QT imports that will be used:
#include <QObject>
#include <QWheelEvent>
#include <QMouseEvent>

// Include header files for View and Model packages:
#include "view.h"
#include "model.h"

// Initialize the Controller class that extends the QObject class:
class Controller : public QObject
{
    Q_OBJECT

public:

    // Define constructor:
    explicit Controller(View *view, Model *model);

    // Define destructor:
    ~Controller();

protected:

    // Define override function for general QT handling events:
    bool eventFilter(QObject *object, QEvent *event) override;

private:

    // Instances of the View and Model classes linking the architecture:
    View *view;
    Model *model;

    // Define function to handle zooming with the mouse wheel:
    void handleZoom(QWheelEvent *wheelEvent);
};

#endif // CONTROLLER_H
