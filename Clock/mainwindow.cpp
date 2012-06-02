#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clockviewfactory.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), _ui(new Ui::MainWindow), _viewNx(0),
    _viewPr(0), _model(0), _modelThread(0)
{
    _ui->setupUi(this);

    _views.reserve(VMODE_MAX);
}

MainWindow::~MainWindow()
{
    delete _ui;
    _ui = 0;

    delete _viewNx;
    _viewNx = 0;

    delete _viewPr;
    _viewPr = 0;

    collectThreads();

    delete _model;
    _model = 0;

    delete _modelThread;
    _modelThread = 0;

    purgeViews();
}


void MainWindow::initAndSetup( )
{
    // stuff
    initViews();
    initModel();
}


void MainWindow::switchViewPrev( )
{

}


void MainWindow::switchViewNext( )
{

}




