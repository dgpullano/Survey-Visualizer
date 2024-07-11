/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QAction *actionFrom_CSV;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuSurvey_Visualizer;
    QMenu *menuImport_Data;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName("View");
        View->resize(800, 600);
        actionFrom_CSV = new QAction(View);
        actionFrom_CSV->setObjectName("actionFrom_CSV");
        centralwidget = new QWidget(View);
        centralwidget->setObjectName("centralwidget");
        View->setCentralWidget(centralwidget);
        menubar = new QMenuBar(View);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuSurvey_Visualizer = new QMenu(menubar);
        menuSurvey_Visualizer->setObjectName("menuSurvey_Visualizer");
        menuImport_Data = new QMenu(menubar);
        menuImport_Data->setObjectName("menuImport_Data");
        View->setMenuBar(menubar);
        statusbar = new QStatusBar(View);
        statusbar->setObjectName("statusbar");
        View->setStatusBar(statusbar);

        menubar->addAction(menuSurvey_Visualizer->menuAction());
        menubar->addAction(menuImport_Data->menuAction());
        menuImport_Data->addAction(actionFrom_CSV);

        retranslateUi(View);

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QCoreApplication::translate("View", "View", nullptr));
        actionFrom_CSV->setText(QCoreApplication::translate("View", "Import Points from CSV", nullptr));
        menuSurvey_Visualizer->setTitle(QCoreApplication::translate("View", "Survey Visualizer", nullptr));
        menuImport_Data->setTitle(QCoreApplication::translate("View", "Import Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
