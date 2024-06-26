// Include references to .h and UI .h files:
#include "view.h"
#include "./ui_view.h"

// Include necessary QT imports that will be used:
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QPen>
#include <QBrush>

// Define the View constructor:
View::View(QWidget *parent) : QMainWindow(parent), ui(new Ui::View)
{

    // Use QT Designer function that reads the view.ui file:
    ui->setupUi(this);

    // Create a QGraphicsScene, set the size, and set the background color:
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 400, 400);
    scene->setBackgroundBrush(Qt::darkGray);

    // Create a QGraphicsView to visualize the scene and set it as the central widget in the main window:
    sceneView = new QGraphicsView(scene, this);
    setCentralWidget(sceneView);

    // Enable scrollbars and drag mode to navigate the scene:
    sceneView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    sceneView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    sceneView->setDragMode(QGraphicsView::ScrollHandDrag);

    // Set the zoom transformation anchor to the mouse position at the time of zoom:
    sceneView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    // Define radius, pen, and brush properties for point visualizations:
    qreal pointRadius = 10.0;
    QPen pointPen(Qt::black);
    QBrush pointBrush(Qt::red);

    // Define pen and pen width for line visualizations:
    QPen linePen(Qt::blue);
    linePen.setWidth(2);

    // Create 3 sample points:
    QGraphicsEllipseItem *samplePoint1 = new QGraphicsEllipseItem(
        QRectF(100 - pointRadius, 100 - pointRadius, 2*pointRadius, 2*pointRadius)
    );
    QGraphicsEllipseItem *samplePoint2 = new QGraphicsEllipseItem(
        QRectF(300 - pointRadius, 100 - pointRadius, 2*pointRadius, 2*pointRadius)
    );
    QGraphicsEllipseItem *samplePoint3 = new QGraphicsEllipseItem(
        QRectF(200 - pointRadius, 300 - pointRadius, 2*pointRadius, 2*pointRadius)
    );

    // Set the pen and brush properties for sample points:
    samplePoint1->setPen(pointPen);
    samplePoint1->setBrush(pointBrush);
    samplePoint2->setPen(pointPen);
    samplePoint2->setBrush(pointBrush);
    samplePoint3->setPen(pointPen);
    samplePoint3->setBrush(pointBrush);

    // Add the sample points to the scene:
    scene->addItem(samplePoint1);
    scene->addItem(samplePoint2);
    scene->addItem(samplePoint3);

    // Create sample lines that connect all sample points:
    QLineF line12(samplePoint1->boundingRect().center(), samplePoint2->boundingRect().center());
    QGraphicsLineItem *sampleLine12 = new QGraphicsLineItem(line12);
    QLineF line23(samplePoint2->boundingRect().center(), samplePoint3->boundingRect().center());
    QGraphicsLineItem *sampleLine23 = new QGraphicsLineItem(line23);
    QLineF line31(samplePoint3->boundingRect().center(), samplePoint1->boundingRect().center());
    QGraphicsLineItem *sampleLine31 = new QGraphicsLineItem(line31);

    // Set the pen properties for sample lines:
    sampleLine12->setPen(linePen);
    sampleLine23->setPen(linePen);
    sampleLine31->setPen(linePen);

    // Add the sample lines to the scene:
    scene->addItem(sampleLine12);
    scene->addItem(sampleLine23);
    scene->addItem(sampleLine31);

    // Render the sample lines under the points:
    sampleLine12->setZValue(-1);
    sampleLine23->setZValue(-1);
    sampleLine31->setZValue(-1);

}

// Define the View destructor:
View::~View()
{
    delete ui;
    delete scene;
}

// Define the getter for sceneView:
QGraphicsView* View::getSceneView() const
{
    return sceneView;
}
