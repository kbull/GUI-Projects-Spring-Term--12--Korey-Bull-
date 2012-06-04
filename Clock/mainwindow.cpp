#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ViewFactory.h"
#include "clockmodel.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), _ui(new Ui::MainWindow), _ctrlThread(0),
    _ctrl(0)
{
    _ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete _ui;
    _ui = 0;

    _ctrlThread->terminate();

    delete _ctrlThread;
    _ctrlThread = 0;

    delete _ctrl;
    _ctrl = 0;

    purgeViews();
}


void MainWindow::initAndSetup( )
{
    setBaseSize(MW_WIDTH, MW_HEIGHT);
    setMaximumSize(MW_WIDTH, MW_HEIGHT);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);


    initViews();
    initController();
}


void MainWindow::switchViewPrev( )
{
    enableButtons(false);
    ViewMode state = ClockModel::getInstance().getCurrentState();

    emit clockViewChanged(false);

    // view change
    switch (state)
    {
    case ANALOG:
        dynamic_cast<AnalogView *>(_views[state])->setEnabled(false);
        break;

    case DIGITAL:
        dynamic_cast<AnalogView *>(_views[state])->setEnabled(false);
        break;

    case BINARY:
        dynamic_cast<AnalogView *>(_views[state])->setEnabled(false);
        break;
    }

    state = ClockModel::getInstance().getCurrentState();

    switch (state)
    {
    case ANALOG:
        dynamic_cast<AnalogView *>(_views[state])->setEnabled(true);
        break;

    case DIGITAL:
        dynamic_cast<AnalogView *>(_views[state])->setEnabled(true);
        break;

    case BINARY:
        dynamic_cast<AnalogView *>(_views[state])->setEnabled(true);
        break;
    }

    _ctrl->registerView(_views[state]);
    _ctrl->forceViewUpdate();
    setCentralWidget(dynamic_cast<QWidget *>(_views[state]));

    enableButtons(true);
}


void MainWindow::switchViewNext( )
{
    enableButtons(false);
    ViewMode state = ClockModel::getInstance().getCurrentState();

    emit clockViewChanged(true);

    // view change
    switch (state)
    {
    case ANALOG:
        dynamic_cast<AnalogView *>(_views[state])->setEnabled(false);
        break;

    case DIGITAL:
        dynamic_cast<AnalogView *>(_views[state])->setEnabled(false);
        break;

    case BINARY:
        dynamic_cast<AnalogView *>(_views[state])->setEnabled(false);
        break;
    }

    state = ClockModel::getInstance().getCurrentState();

    switch (state)
    {
    case ANALOG:
        dynamic_cast<AnalogView *>(_views[state])->setEnabled(true);
        break;

    case DIGITAL:
        dynamic_cast<AnalogView *>(_views[state])->setEnabled(true);
        break;

    case BINARY:
        dynamic_cast<AnalogView *>(_views[state])->setEnabled(true);
        break;
    }

    _ctrl->registerView(_views[state]);
    _ctrl->forceViewUpdate();
    setCentralWidget(dynamic_cast<QWidget *>(_views[state]));

    enableButtons(true);
}


void MainWindow::closeEvent(QCloseEvent * close)
{
    // thread collection
    _ctrlThread->terminate();
    _ctrlThread->wait(10);
}


void MainWindow::purgeViews()
{
    foreach (ViewMode key, _views.keys())
    {
        delete _views[key];
        _views[key] = 0;
    }

    _views.clear();
}


void MainWindow::initViews()
{
    ViewFactory * factory = new ViewFactory;

    _views[ANALOG] = factory->createAnalogView();
    _views[DIGITAL] = factory->createDigitalView();
    _views[BINARY] = factory->createBinaryView();

    setCentralWidget(dynamic_cast<QWidget *>(_views[ANALOG]));

    foreach (ViewMode key, _views.keys())
    {
        switch (key)
        {
        case ANALOG:
            dynamic_cast<AnalogView *>(_views[key])->setEnabled(true);
            break;

        case DIGITAL:
            dynamic_cast<DigitalView *>(_views[key])->setEnabled(false);
            break;

        case BINARY:
            dynamic_cast<BinaryView *>(_views[key])->setEnabled(false);
            break;
        }
    }

    delete factory;
}


void MainWindow::initController()
{
    _ctrl = new ClockController;
    _ctrlThread = new QThread;

    _ctrl->moveToThread(_ctrlThread);


    connect(_ctrl, SIGNAL(supplyNewData(quint8*,quint8)),
            dynamic_cast<AnalogView *>(_views[ANALOG]), SLOT(updateState(quint8*,quint8)));

    connect(&(ClockModel::getInstance()), SIGNAL(notify()), _ctrl, SLOT(updateViewData()));
    connect(this, SIGNAL(clockViewChanged(bool)), _ctrl, SLOT(updateModel(bool)));

    _ctrlThread->start();
}


void MainWindow::enableButtons(bool enable)
{

}
