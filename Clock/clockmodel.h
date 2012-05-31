#ifndef CLOCKMODEL_H
#define CLOCKMODEL_H

#include <QObject>
#include <QMutex>
#include <QTimer>
#include <QTime>
#include <QList>
#include "ISubject.h"
#include "Enumerations.h"

class ClockModel : public QObject, public ISubject
{
    Q_OBJECT

public:    
    explicit ClockModel(QObject *parent = 0);
    virtual ~ClockModel();

    ViewMode getCurrentState( ) const;
    QTime getCurrentTime( ) const;
    bool isRunning() const;

    virtual void registerObserver(QWidget *);
    virtual void removeObserver(QWidget *);

protected:

signals:
    virtual void notify();
    
public slots:
    void startTimer();
    void timerComplete();
    void changeState(ViewMode);

private:
    ViewMode _currentState;
    QTimer * _timer;
    bool _running;
    QTime _curTime;
    mutable QMutex _mutex;


    ClockModel(const ClockModel &);
    ClockModel & operator=(const ClockModel &);

};

#endif // CLOCKMODEL_H
