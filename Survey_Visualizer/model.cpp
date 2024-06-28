// Include references to .h files:
#include "model.h"

// Include necessary QT imports that will be used:
#include <QFile>
#include <QTextStream>
#include <QDebug>

Model::Model(QObject *parent) : QObject(parent) {

    // ** Eventually I will add the SQLite model definition here.
    // ** I.E. the tables and DB schema will be defined.
}

Model::~Model() {

    // ** Eventually I will remove the SQLite session data here.
}

bool Model::loadPointsFromCSV(const QString &filePath, QString &fileFormat) {

    // Create the QT file from filePath:
    QFile file(filePath);

    // Check that the file opens successfully in read-only and text mode:
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {

        // Output error message if not successful:
        qDebug() << "Could not open file: " << filePath;
        return false;
    }

    // Open the CSV file stream:
    QTextStream csvStream(&file);

    // Read in the headers separated by commas:
    QStringList headers = csvStream.readLine().split(',');

    // Until the end of the file:
    while(!csvStream.atEnd()) {

        // Process the current line into values:
        QStringList values = csvStream.readLine().split(',');

        // Process line based on 8 supported fileFormats:
        if(fileFormat == "PNEZD" && values.size() == 5) {

        } else if(fileFormat == "PENZD" && values.size() == 5) {

        } else if(fileFormat == "PNEZ" && values.size() == 4) {

        } else if(fileFormat == "PENZ" && values.size() == 4) {

        } else if(fileFormat == "PNED" && values.size() == 4) {

        } else if(fileFormat == "PEND" && values.size() == 4) {

        } else if(fileFormat == "PNE" && values.size() == 3) {

        } else if(fileFormat == "PEN" && values.size() == 3) {

        }
    }
}
