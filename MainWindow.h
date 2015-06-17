#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class DuCanvas;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionQuitar_triggered();

private:
    Ui::MainWindow *ui;
    DuCanvas *mCanvas;
};

#endif // MAINWINDOW_H
