/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QLabel *currentFileLabel;
    QPlainTextEdit *scanLogEdit;
    QProgressBar *progressBar;
    QLineEdit *currentFileLineEdit;
    QPushButton *scanButton;
    QPushButton *meshButton;
    QPushButton *resetButton;
    QPushButton *cancelButton;
    QLineEdit *newFileLineEdit;
    QLabel *newFileLabel;
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
        currentFileLabel = new QLabel(centralWidget);
        currentFileLabel->setObjectName(QString::fromUtf8("currentFileLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(currentFileLabel->sizePolicy().hasHeightForWidth());
        currentFileLabel->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(currentFileLabel, 4, 2, 1, 1);

        scanLogEdit = new QPlainTextEdit(centralWidget);
        scanLogEdit->setObjectName(QString::fromUtf8("scanLogEdit"));

        gridLayout_2->addWidget(scanLogEdit, 0, 0, 7, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout_2->addWidget(progressBar, 7, 0, 1, 1);

        currentFileLineEdit = new QLineEdit(centralWidget);
        currentFileLineEdit->setObjectName(QString::fromUtf8("currentFileLineEdit"));
        currentFileLineEdit->setAutoFillBackground(false);
        currentFileLineEdit->setReadOnly(true);

        gridLayout_2->addWidget(currentFileLineEdit, 5, 2, 1, 2);

        scanButton = new QPushButton(centralWidget);
        scanButton->setObjectName(QString::fromUtf8("scanButton"));

        gridLayout_2->addWidget(scanButton, 3, 2, 1, 2);

        meshButton = new QPushButton(centralWidget);
        meshButton->setObjectName(QString::fromUtf8("meshButton"));

        gridLayout_2->addWidget(meshButton, 6, 2, 1, 2);

        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        gridLayout_2->addWidget(resetButton, 7, 3, 1, 1);

        cancelButton = new QPushButton(centralWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout_2->addWidget(cancelButton, 7, 2, 1, 1);

        newFileLineEdit = new QLineEdit(centralWidget);
        newFileLineEdit->setObjectName(QString::fromUtf8("newFileLineEdit"));

        gridLayout_2->addWidget(newFileLineEdit, 2, 2, 1, 2);

        newFileLabel = new QLabel(centralWidget);
        newFileLabel->setObjectName(QString::fromUtf8("newFileLabel"));
        sizePolicy.setHeightForWidth(newFileLabel->sizePolicy().hasHeightForWidth());
        newFileLabel->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(newFileLabel, 1, 2, 1, 1);

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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        currentFileLabel->setText(QApplication::translate("MainWindow", "Current File:", 0, QApplication::UnicodeUTF8));
        scanButton->setText(QApplication::translate("MainWindow", "Scan", 0, QApplication::UnicodeUTF8));
        meshButton->setText(QApplication::translate("MainWindow", "Mesh", 0, QApplication::UnicodeUTF8));
        resetButton->setText(QApplication::translate("MainWindow", "Reset Hardware", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("MainWindow", "Cancel Scan", 0, QApplication::UnicodeUTF8));
        newFileLabel->setText(QApplication::translate("MainWindow", "New File:", 0, QApplication::UnicodeUTF8));
        menu3D_Cop->setTitle(QApplication::translate("MainWindow", "3D Copy", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
