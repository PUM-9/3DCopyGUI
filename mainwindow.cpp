#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->meshButton, SIGNAL (released()), this, SLOT (handleMeshButton()));
    connect(ui->scanButton, SIGNAL (released()), this, SLOT (handleScanButton()));
    connect(ui->cancelButton, SIGNAL (released()), this, SLOT (handleCancelButton()));
    connect(ui->resetButton, SIGNAL (released()), this, SLOT (handleResetButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleMeshButton()
{
    QString filePath(QFileDialog::getOpenFileName(this,tr("Open File"),"./","PCD Files (*.pcd)"));
    QFileInfo fileInfo(filePath);
    QString fileName(fileInfo.fileName());
    ui->currentFileLineEdit->setText(fileName);
    ui->scanLogEdit->appendPlainText("OPEN: " + fileName);
}

void MainWindow::handleScanButton()
{
    QString name(ui->newFileLineEdit->text());
    ui->scanLogEdit->appendPlainText("SCAN: " + name);
    // TODO: Call to wrapper to initialize scan with selected name
}

void MainWindow::handleCancelButton()
{
    ui->scanLogEdit->appendPlainText("CANCEL");
    // TODO: Call to wrapper to cancel the ongoing scan
}

void MainWindow::handleResetButton()
{
    ui->scanLogEdit->appendPlainText("RESET");
    // TODO: Call to wrapper to reset the hardware to default settings
}
