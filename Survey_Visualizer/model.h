#ifndef MODEL_H
#define MODEL_H

// Include necessary QT imports that will be used:
#include <QObject>
#include <QVector>
#include <QString>

// Define the structure for a 2D point:
struct Point2D {
    int id;
    double northing;
    double easting;
    QString description;
};

// Define the structure for a 3D point:
struct Point3D {
    int id;
    double northing;
    double easting;
    double elevation;
    QString description;
};

// Define the structure for a 2D line:
struct Line2D {
    int id;
    int startPtId;
    int endPtId;
    double length;
};

// Define the structure for a 3D line:
struct Line3D {
    int id;
    int startPtId;
    int endPtId;
    double length;
};

class Model : public QObject
{
    Q_OBJECT

public:

    // Define constructor:
    explicit Model(QObject *parent = nullptr);

    // Define destructor:
    ~Model();

    // Define function to load in points from a CSV:
    bool loadPointsFromCSV(const QString &filePath, QString &fileFormat, bool headerPresent);

    // Define getters for points and lines:
    const QVector<Point2D>& getPoints2D() const { return points2D; }
    const QVector<Point3D>& getPoints3D() const { return points3D; }
    const QVector<Line2D>& getLines2D() const { return lines2D; }
    const QVector<Line3D>& getLines3D() const { return lines3D; }

private:

    QVector<Point2D> points2D;
    QVector<Point3D> points3D;
    QVector<Line2D> lines2D;
    QVector<Line3D> lines3D;
};

#endif // MODEL_H
