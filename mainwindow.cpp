#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "include/Mesh.h"
#include "include/Registration.h"
#include <pcl/io/vtk_lib_io.h>
#include <iostream>

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->meshButton, SIGNAL (released()), this, SLOT (handleMeshButton()));
    connect(ui->registerButton, SIGNAL (released()), this, SLOT (handleRegisterButton()));
    connect(ui->registerValueResetButton, SIGNAL (released()), this, SLOT (handleRegisterValueResetButton()));

    ui->maxCorrDistLEdit->setText(QString::number(default_max_correspondence_distance));
    ui->maxIterLEdit->setText(QString::number(default_max_iterations));
    ui->transEpsLEdit->setText(QString::number(default_transformation_epsilon));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Handles release of the mesh button in the GUI.
 */
void MainWindow::handleMeshButton() {

    QString file_path(QFileDialog::getOpenFileName(this,tr("Mesh File"),"/home","PCD Files (*.pcd)"));
    QFileInfo file_info(file_path);
    QDir dir_path(file_info.absoluteDir());
    QString file_name(file_info.fileName());
    QString base_name(file_info.baseName());

    if(!file_name.isEmpty()&& !file_name.isNull()){
        Mesh mesh = Mesh();

        ui->scanLogEdit->appendPlainText("Meshing file: " + file_name);

        PointCloud::Ptr point_cloud_ptr (new PointCloud);
        pcl::io::loadPCDFile(file_name.toStdString(), *point_cloud_ptr);
        pcl::PolygonMesh polygon_mesh = mesh.mesh(point_cloud_ptr);

        std::stringstream ss;
        ss << dir_path.absolutePath().toStdString() << "/" << base_name.toStdString() << ".stl";
        save_mesh(polygon_mesh, ss.str());
    }
}

/*
 * Handles release of the register button in the GUI.
 */
void MainWindow::handleRegisterButton()
{
    QString folder_path(QFileDialog::getExistingDirectory(this,tr("Register Folder"),"/home",
                                                          QFileDialog::DontResolveSymlinks));

    std::vector<fs::path> file_paths;
    fs::path folder_path_p(folder_path.toStdString());

    // Check if a folder was selected / does not exist
    if(!folder_path.isEmpty() && !folder_path.isNull()) {

        ui->scanLogEdit->appendPlainText("Registering folder: " + folder_path);

        get_all_pcd_files(folder_path_p,file_paths);

        // Check if we have more than one file to register
        if(file_paths.size() >= 2) {

            Registration registration = Registration();

            registration.set_max_correspondence_distance(ui->maxCorrDistLEdit->text().toDouble());
            registration.set_max_iterations(ui->maxIterLEdit->text().toInt());
            registration.set_transformation_epsilon(ui->maxIterLEdit->text().toDouble());

            std::vector<PointCloud::Ptr> point_clouds;

            for(auto it=file_paths.begin(); it!=file_paths.end(); ++it) {
                PointCloud::Ptr point_cloud_ptr (new PointCloud);
                pcl::io::loadPCDFile((*it).string(), *point_cloud_ptr);
                point_clouds.push_back(point_cloud_ptr);
            }

            // Create folder for registered point_cloud
            if(fs::create_directory(folder_path_p += "/registered")){
                cout << "folder created" << endl;
            } else {
                cout << "folder already exists" << endl;
            }

            PointCloud::Ptr point_cloud = registration.register_point_clouds(point_clouds);

            std::stringstream ss;
            ss << folder_path_p.string();
            cout << ss.str() << endl;
            ss << "/" << ui->newFileNameLEdit->text().toStdString() << ".pcd";

            save_point_cloud(point_cloud, ss.str());

            for (int i = 0; i < file_paths.size(); ++i) {
                std::cout << file_paths[i].string() << std::endl;
            }
        }
    }
}

void MainWindow::handleRegisterValueResetButton()
{
    ui->maxCorrDistLEdit->setText(QString::number(default_max_correspondence_distance));
    ui->maxIterLEdit->setText(QString::number(default_max_iterations));
    ui->transEpsLEdit->setText(QString::number(default_transformation_epsilon));
}

/**
 * Saves a Polygon Mesh to .stl file accordingly to the input from the user.
 *
 * @param polygon_mesh The Polygon Mesh to be saved.
 * @param file_name The file name of the stl file.
 */
void MainWindow::save_mesh(const pcl::PolygonMesh polygon_mesh, const std::string file_name) {
    pcl::io::savePolygonFileSTL(file_name, polygon_mesh);
}

void MainWindow::save_point_cloud(const PointCloud::Ptr point_cloud, const std::string file_name) {
    pcl::io::savePCDFile(file_name, *point_cloud);
}

/**
 * Takes all .pcd files in a folder and adds their paths to the file_paths vector.
 *
 * @param folder_path The path to the folder that should be searched.
 * @param file_paths The vector that stores the file paths to all .pcd files.
 */
void MainWindow::get_all_pcd_files(const fs::path& folder_path, std::vector<fs::path>& file_paths) {

    fs::directory_iterator end;
    fs::directory_iterator it(folder_path);

    while(it != end) {
        if(fs::is_regular_file(*it) && it->path().extension() == ".pcd") file_paths.push_back((it->path()));
        ++it;
    }

}
