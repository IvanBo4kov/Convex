#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calcButton_clicked()
{
   solve::getInstance().convex_hull();
   this->repaint();
}

void MainWindow::on_clearButton_clicked()
{
    solve::getInstance().clear();
    this->repaint();
}

