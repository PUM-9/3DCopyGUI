#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>

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
    void handleScanButton();
    void handleCancelButton();
    void handleResetButton();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
