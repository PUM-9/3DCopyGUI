#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "include/Mesh.h"
#include <pcl/io/vtk_lib_io.h>

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

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

/*
 * Handles release of the mesh button in the GUI.
 */
void MainWindow::handleMeshButton() {

    Mesh mesh = Mesh();

    QString filePath(QFileDialog::getOpenFileName(this,tr("Open File"),"./","PCD Files (*.pcd)"));
    QFileInfo fileInfo(filePath);
    QString fileName(fileInfo.fileName());
    ui->currentFileLineEdit->setText(fileName);
    ui->scanLogEdit->appendPlainText("OPEN: " + fileName);

    PointCloud::Ptr point_cloud_ptr (new PointCloud);
    pcl::io::loadPCDFile(fileName.toStdString(), *point_cloud_ptr);
    pcl::PolygonMesh polygon_mesh = mesh.mesh(point_cloud_ptr);
    save_mesh(polygon_mesh);
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

/**
 * Saves a Polygon Mesh to .stl file accordingly to the input from the user.
 *
 * @param polygon_mesh The Polygon Mesh to be saved.
 */
void MainWindow::save_mesh(const pcl::PolygonMesh polygon_mesh) {
    std::stringstream ss;
    ss << "test.stl";
    pcl::io::savePolygonFileSTL(ss.str(), polygon_mesh);
    std::cout << "Saved mesh to " << ss.str() << std::endl;
}
