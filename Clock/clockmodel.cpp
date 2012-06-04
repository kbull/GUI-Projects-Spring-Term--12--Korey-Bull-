#include "clockmodel.h"
#include <QApplication>

QMutex ClockModel::_mutex;


ClockModel::ClockModel(QObject *parent) :
    QObject(parent), _timer(0), _currentState(ANALOG),
    _running(false), _curTime(QTime::currentTime())
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


ClockModel & ClockModel::getInstance()
{
    static ClockModel instance;

    return instance;
}


ViewMode ClockModel::getCurrentState() const
{
    return _currentState;
}


void ClockModel::getBCDTime(quint8 &ht, quint8 &ho, quint8 &mt, quint8 &mo, quint8 &st, quint8 &so)
{
    QMutexLocker lock(&_mutex);
    quint8 h = 0;

    h = (quint8)_curTime.hour();

    if (h % 10 == 0)
    {
        ht = 0;
        ho = h;
    }
    else
    {
        ht = 1;
        ho = h % 10;
    }

    h = (quint8)_curTime.minute();

    mt = h / 10;
    mo = h % 10;

    h = (quint8)_curTime.second();

    st = h / 10;
    so = h % 10;
}


void ClockModel::getDecimalTime(quint8 &h, quint8 &m, quint8 &s)
{
    QMutexLocker lock(&_mutex);

    h = (quint8)_curTime.hour();
    m = (quint8)_curTime.minute();
    s = (quint8)_curTime.second();
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

    if (!_timer->isActive())
    {
        _timer->start(1000);
        _running = true;
    }
}


void ClockModel::stopTimer( )
{
    if (_timer)
    {
        _timer->stop();
        _running = false;
    }
}


void ClockModel::timerComplete( )
{
    _curTime = QTime::currentTime();
    startTimer();

    emit notify();
}


void ClockModel::changeState(bool dir)
{
    QMutexLocker lock(&_mutex);

    switch (_currentState)
    {
    case ANALOG:

        if (dir)
            _currentState = DIGITAL;
        else
            _currentState = BINARY;
        break;

    case DIGITAL:

        if (dir)
            _currentState = BINARY;
        else
            _currentState = ANALOG;
        break;

    case BINARY:

        if (dir)
            _currentState = ANALOG;
        else
            _currentState = DIGITAL;
        break;

    }
}
