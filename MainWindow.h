#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>

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
    void on_pathSearch_clicked();

    void on_load_clicked();
    void on_link_clicked();

    void onClassSelectionChanged(QModelIndex const &current, QModelIndex const &previous);

    void on_showFields_clicked();
    void on_showMethods_clicked();

    void on_action_Edit_JVMConfig_triggered();

    void on_action_Edit_Bitmap2D_triggered();

    void on_action_Edit_Bitmap3D_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
