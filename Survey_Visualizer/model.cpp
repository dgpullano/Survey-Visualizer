// Include references to .h files:
#include "model.h"

// Include necessary QT imports that will be used:
#include <QFile>
#include <QTextStream>
#include <QDebug>

// Define the Model constructor:
Model::Model(QObject *parent) : QObject(parent) {

    // ** Eventually I will add the SQLite model definition here.
    // ** I.E. the tables and DB schema will be defined.
}

// Define the Model destructor:
Model::~Model() {

    // ** Eventually I will remove the SQLite session data here.
}

// Define the function to load in points from a CSV:
bool Model::loadPointsFromCSV(const QString &filePath, QString &fileFormat, bool headerPresent) {

    // Create the QT file from filePath:
    QFile csvFile(filePath);

    // Check that the file opens successfully in read-only and text mode:
    if(!csvFile.open(QIODevice::ReadOnly | QIODevice::Text)) {

        // Output error message if not successful:
        qDebug() << "Could not open file: " << filePath;
        return false;
    }

    // Open the CSV file stream:
    QTextStream csvStream(&csvFile);

    // Skip the headers line if it exists in the file:
    if(headerPresent) {
        csvStream.readLine();
    }

    // Process each point until at the end of the file:
    while(!csvStream.atEnd()) {

        // Read current line and split into values using comma:
        // NOTE: Descriptions cannot contain a comma (for now)
        QStringList values = csvStream.readLine().trimmed().split(',');

        //-----------------------------------------------
        // Store values based on 8 supported fileFormats:
        //-----------------------------------------------

        // When 3D format is [id, northing, easting, elevation, description]:
        if(fileFormat == "PNEZD" && values.size() == 5) {
            Point3D point;
            point.id = values[0].toInt();
            point.northing = values[1].toDouble();
            point.easting = values[2].toDouble();
            point.elevation = values[3].toDouble();
            point.description = values[4];
            points3D.append(point);

        // When 3D format is [id, easting, northing, elevation, description]:
        } else if(fileFormat == "PENZD" && values.size() == 5) {
            Point3D point;
            point.id = values[0].toInt();
            point.easting = values[1].toDouble();
            point.northing = values[2].toDouble();
            point.elevation = values[3].toDouble();
            point.description = values[4];
            points3D.append(point);

        // When 3D format is [id, northing, easting, elevation]:
        } else if(fileFormat == "PNEZ" && values.size() == 4) {
            Point3D point;
            point.id = values[0].toInt();
            point.northing = values[1].toDouble();
            point.easting = values[2].toDouble();
            point.elevation = values[3].toDouble();
            point.description = "";
            points3D.append(point);

        // When 3D format is [id, easting, northing, elevation]:
        } else if(fileFormat == "PENZ" && values.size() == 4) {
            Point3D point;
            point.id = values[0].toInt();
            point.easting = values[1].toDouble();
            point.northing = values[2].toDouble();
            point.elevation = values[3].toDouble();
            point.description = "";
            points3D.append(point);

        // When 2D format is [id, northing, easting, description]:
        } else if(fileFormat == "PNED" && values.size() == 4) {
            Point2D point;
            point.id = values[0].toInt();
            point.northing = values[1].toDouble();
            point.easting = values[2].toDouble();
            point.description = values[3];
            points2D.append(point);

        // When 2D format is [id, easting, northing, description]:
        } else if(fileFormat == "PEND" && values.size() == 4) {
            Point2D point;
            point.id = values[0].toInt();
            point.easting = values[1].toDouble();
            point.northing = values[2].toDouble();
            point.description = values[3];
            points2D.append(point);

        // When 2D format is [id, northing, easting]:
        } else if(fileFormat == "PNE" && values.size() == 3) {
            Point2D point;
            point.id = values[0].toInt();
            point.northing = values[1].toDouble();
            point.easting = values[2].toDouble();
            point.description = "";
            points2D.append(point);

        // When 2D format is [id, easting, northing]:
        } else if(fileFormat == "PEN" && values.size() == 3) {
            Point2D point;
            point.id = values[0].toInt();
            point.easting = values[1].toDouble();
            point.northing = values[2].toDouble();
            point.description = "";
            points2D.append(point);

        // When format of data does not match supported types:
        } else {
            qDebug() << "Unexpected data format. Does not match: " << fileFormat;
        }
    }

    // Close the file path after it has been read:
    csvFile.close();
    return true;
}
