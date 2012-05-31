#include "clockmodel.h"

ClockModel::ClockModel(QObject *parent) :
    QObject(parent), _timer(0), _currentState(ANALOG),
    _running(false)
{
}


ClockModel::~ClockModel()
{
    QMutexLocker lock(&_mutex);

    delete _timer;
    _timer = 0;

    _running = false;
    _currentState = ANALOG;
}


ViewMode ClockModel::getCurrentState() const
{
    return _currentState;
}


bool ClockModel::isRunning() const
{
    return _running;
}


void ClockModel::startTimer( )
{
    QMutexLocker lock(&_mutex);

    if (!_timer)
    {
        _timer = new QTimer;
        connect(_timer, SIGNAL(timeout()), this, SLOT(timerComplete()));
    }

    _timer->start(1000);
    _running = true;
}


void ClockModel::timerComplete( )
{
    emit notify();

    startTimer();
}


void ClockModel::changeState(ViewMode newState)
{
    QMutexLocker lock(&_mutex);

    _currentState = newState;
}
