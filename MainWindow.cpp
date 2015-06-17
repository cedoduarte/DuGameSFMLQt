#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DuCanvas.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mCanvas = new DuCanvas(this, QPoint(0, 0), size());
    setCentralWidget(mCanvas);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitar_triggered()
{
    close();
}
