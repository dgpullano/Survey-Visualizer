// Include references to .h files:
#include "controller.h"
#include "view.h"
#include "model.h"

// Include necessary QT imports that will be used:
#include <QGraphicsView>

// Define the Controller constructor:
Controller::Controller(View *view, Model *model) : QObject(view), view(view), model(model)
{
    // Install controller as the QT event filter for the view's viewport:
    view->getSceneView()->viewport()->installEventFilter(this);
}

// Define the Controller destructor:
Controller::~Controller()
{
    delete view;
    delete model;
}

// Define override function for general QT handling events:
bool Controller::eventFilter(QObject *object, QEvent *event)
{
    // Check is the object is the viewport and the event is a wheel scroll:
    if(object == view->getSceneView()->viewport() && event->type() == QEvent::Wheel) {

        // Cast the event to a QWheelEvent for zoom handling:
        QWheelEvent *wheelEvent = static_cast<QWheelEvent *>(event);

        // Handle the zoom operation:
        handleZoom(wheelEvent);

        // Indicate that the event has been handled properly:
        return true;
    }

    // Let QT handle the event if it doesn't match the conditions above:
    return QObject::eventFilter(object, event);
}

// Define function to handle zooming with the mouse wheel:
void Controller::handleZoom(QWheelEvent *wheelEvent)
{
    // Set the amount a single scroll will zoom in or out:
    qreal scaleChange = 0.15;   // 15% currently

    // When scrolling up zoom in:
    if(wheelEvent->angleDelta().y() > 0) {
        view->getSceneView()->scale(1 + scaleChange, 1 + scaleChange);

    // When scrolling down zoom out:
    } else {
        view->getSceneView()->scale(1 - scaleChange, 1 - scaleChange);
    }


}
