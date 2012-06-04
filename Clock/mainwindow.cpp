#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clockviewfactory.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), _ui(new Ui::MainWindow), _viewNx(0),
    _viewPr(0), _ctrlThread(0), _ctrl(0)
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

    delete _ctrlThread;
    _ctrlThread = 0;

    delete _ctrl;
    _ctrl = 0;

    purgeViews();
}


void MainWindow::initAndSetup( )
{
    // stuff
    initViews();
    initController();
}


void MainWindow::switchViewPrev( )
{
    emit clockViewChanged(false);
}


void MainWindow::switchViewNext( )
{
    emit clockViewChanged(true);
}


void MainWindow::purgeViews()
{

}


void MainWindow::initViews()
{

}


void MainWindow::initController()
{

}


void MainWindow::collectThreads()
{

}

