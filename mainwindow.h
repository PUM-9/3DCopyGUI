#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>
#include <pcl/PolygonMesh.h>
#include <boost/filesystem.hpp>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

namespace fs = boost::filesystem;

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void handleMeshButton();
    void handleRegisterButton();
    void handleRegisterValueResetButton();

private:
    // Fields
    Ui::MainWindow *ui;
    double default_max_correspondence_distance = 15;
    unsigned int default_max_iterations = 100;
    double default_transformation_epsilon = 1e-7;

    // Methods
    void save_mesh(const pcl::PolygonMesh polygon_mesh, const std::string file_name);
    void save_point_cloud(const pcl::PointCloud<pcl::PointXYZ>::Ptr point_cloud, const std::string file_name);
    void get_all_pcd_files(const fs::path& folder_path, std::vector<fs::path>& file_paths);
};

#endif // MAINWINDOW_H
