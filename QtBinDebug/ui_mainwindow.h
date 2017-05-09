/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QStatusBar>
#include <QToolBar>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QPlainTextEdit *scanLogEdit;
    QLabel *registrationValuesLabel;
    QLabel *meshLabel;
    QPushButton *meshButton;
    QLabel *maxCorrDistLabel;
    QLabel *transEpsLabel;
    QLabel *maxIterLabel;
    QLineEdit *transEpsLEdit;
    QLineEdit *newFileNameLEdit;
    QPushButton *registerButton;
    QLabel *newFileNameLabel;
    QLineEdit *maxIterLEdit;
    QLineEdit *maxCorrDistLEdit;
    QPushButton *registerValueResetButton;
    QLabel *registrationLabel;
    QMenuBar *menuBar;
    QMenu *menu3D_Cop;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 522);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scanLogEdit = new QPlainTextEdit(centralWidget);
        scanLogEdit->setObjectName(QString::fromUtf8("scanLogEdit"));
        scanLogEdit->setReadOnly(true);

        gridLayout_2->addWidget(scanLogEdit, 1, 0, 12, 1);

        registrationValuesLabel = new QLabel(centralWidget);
        registrationValuesLabel->setObjectName(QString::fromUtf8("registrationValuesLabel"));
        registrationValuesLabel->setMaximumSize(QSize(16777215, 25));
        registrationValuesLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(registrationValuesLabel, 1, 2, 1, 2);

        meshLabel = new QLabel(centralWidget);
        meshLabel->setObjectName(QString::fromUtf8("meshLabel"));
        meshLabel->setMaximumSize(QSize(16777215, 25));
        meshLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(meshLabel, 8, 2, 1, 2);

        meshButton = new QPushButton(centralWidget);
        meshButton->setObjectName(QString::fromUtf8("meshButton"));

        gridLayout_2->addWidget(meshButton, 9, 2, 1, 2);

        maxCorrDistLabel = new QLabel(centralWidget);
        maxCorrDistLabel->setObjectName(QString::fromUtf8("maxCorrDistLabel"));

        gridLayout_2->addWidget(maxCorrDistLabel, 2, 2, 1, 1);

        transEpsLabel = new QLabel(centralWidget);
        transEpsLabel->setObjectName(QString::fromUtf8("transEpsLabel"));

        gridLayout_2->addWidget(transEpsLabel, 4, 2, 1, 1);

        maxIterLabel = new QLabel(centralWidget);
        maxIterLabel->setObjectName(QString::fromUtf8("maxIterLabel"));

        gridLayout_2->addWidget(maxIterLabel, 3, 2, 1, 1);

        transEpsLEdit = new QLineEdit(centralWidget);
        transEpsLEdit->setObjectName(QString::fromUtf8("transEpsLEdit"));
        transEpsLEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(transEpsLEdit, 4, 3, 1, 1);

        newFileNameLEdit = new QLineEdit(centralWidget);
        newFileNameLEdit->setObjectName(QString::fromUtf8("newFileNameLEdit"));
        newFileNameLEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(newFileNameLEdit, 6, 3, 1, 1);

        registerButton = new QPushButton(centralWidget);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));

        gridLayout_2->addWidget(registerButton, 7, 2, 1, 1);

        newFileNameLabel = new QLabel(centralWidget);
        newFileNameLabel->setObjectName(QString::fromUtf8("newFileNameLabel"));

        gridLayout_2->addWidget(newFileNameLabel, 6, 2, 1, 1);

        maxIterLEdit = new QLineEdit(centralWidget);
        maxIterLEdit->setObjectName(QString::fromUtf8("maxIterLEdit"));
        maxIterLEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(maxIterLEdit, 3, 3, 1, 1);

        maxCorrDistLEdit = new QLineEdit(centralWidget);
        maxCorrDistLEdit->setObjectName(QString::fromUtf8("maxCorrDistLEdit"));
        maxCorrDistLEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(maxCorrDistLEdit, 2, 3, 1, 1);

        registerValueResetButton = new QPushButton(centralWidget);
        registerValueResetButton->setObjectName(QString::fromUtf8("registerValueResetButton"));

        gridLayout_2->addWidget(registerValueResetButton, 7, 3, 1, 1);

        registrationLabel = new QLabel(centralWidget);
        registrationLabel->setObjectName(QString::fromUtf8("registrationLabel"));
        registrationLabel->setMaximumSize(QSize(16777215, 25));
        registrationLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(registrationLabel, 5, 2, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 25));
        menu3D_Cop = new QMenu(menuBar);
        menu3D_Cop->setObjectName(QString::fromUtf8("menu3D_Cop"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu3D_Cop->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        registrationValuesLabel->setText(QApplication::translate("MainWindow", "- Registration Values  -", 0));
        meshLabel->setText(QApplication::translate("MainWindow", "- Meshing -", 0));
        meshButton->setText(QApplication::translate("MainWindow", "Mesh", 0));
        maxCorrDistLabel->setText(QApplication::translate("MainWindow", "Max correspondence distance:", 0));
        transEpsLabel->setText(QApplication::translate("MainWindow", "Transformation epsilon:", 0));
        maxIterLabel->setText(QApplication::translate("MainWindow", "Max iterations:", 0));
        registerButton->setText(QApplication::translate("MainWindow", "Register", 0));
        newFileNameLabel->setText(QApplication::translate("MainWindow", "New file name:", 0));
        registerValueResetButton->setText(QApplication::translate("MainWindow", "Reset Values", 0));
        registrationLabel->setText(QApplication::translate("MainWindow", "- Registration -", 0));
        menu3D_Cop->setTitle(QApplication::translate("MainWindow", "3D Copy", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
