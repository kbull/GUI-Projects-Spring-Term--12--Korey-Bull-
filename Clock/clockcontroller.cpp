#include "clockcontroller.h"
#include "UpdaterFactory.h"
#include "clockmodel.h"
#include <QApplication>


ClockController::ClockController()
    : _cView(0), _modelT(new QThread)
{
    ClockModel::getInstance().moveToThread(_modelT);

    _modelT->start();
}


ClockController::~ClockController()
{
    _cView = 0;

    _modelT->quit();
    delete _modelT;
    _modelT = 0;
}


void ClockController::forceViewUpdate()
{
    QMutexLocker lock(&_mutex);
    UpdaterFactory * factory = new UpdaterFactory;
    quint8 * data = 0;
    quint8 size = 0;

    if (nstate == ANALOG)
        DecUpdater * updater = factory->createDec();
    else
        BCDUpdater * updater = factory->createBCD();

    size = updater->initData(data);

    delete updater;
    delete factory;

    emit supplyNewData(data, size);

    delete [] data;
    data = 0;
}


void ClockController::registerView(ClockView * view)
{
    if (view)
    {
        if (_cView)
            QApplication::disconnect(_cView, SLOT(updateState(quint8*,quint8)));

        _cView = view;
        QApplication::connect(this, SIGNAL(supplyNewData(quint8*,quint8)),
                              _cView, SLOT(updateState(quint8*,quint8)));
    }
}


void ClockController::updateModel(bool dir)
{
    ClockModel::getInstance().changeState(dir);
}


void ClockController::updateViewData()
{
    forceViewUpdate();
}
