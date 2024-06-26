#ifndef VIEW_H
#define VIEW_H

// Include necessary QT imports that will be used:
#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QTextEdit>
#include <QGraphicsScene>
#include <QGraphicsView>

// Initialize Ui namespace:
QT_BEGIN_NAMESPACE
namespace Ui {

    // Add View to Ui namespace (i.e. Ui::View):
    class View;
}
QT_END_NAMESPACE

// Initialize the View class that extends the QMainWindow class:
class View : public QMainWindow
{
    Q_OBJECT

public:

    // Define constructor:
    explicit View(QWidget *parent = nullptr);

    // Define destructor:
    ~View();

    // Define the getter for sceneView:
    QGraphicsView* getSceneView() const;

private:

    // Define variable ui which is of type Ui::View:
    Ui::View *ui;

    // Define scene to hold graphical items:
    QGraphicsScene *scene;

    // Define graphics view to visualize the scene:
    QGraphicsView *sceneView;
};

#endif // VIEW_H
