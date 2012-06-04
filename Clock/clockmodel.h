#ifndef CLOCKMODEL_H
#define CLOCKMODEL_H

#include <QObject>
#include <QMutex>
#include <QTimer>
#include <QTime>
#include <QList>
#include "Enumerations.h"


class ClockModel : public QObject
{
    Q_OBJECT

public:        
    virtual ~ClockModel();

    static ClockModel & getInstance( );
    ViewMode getCurrentState( ) const;
    void getDecimalTime(quint8 & h, quint8 & m, quint8 & s);
    void getBCDTime(quint8 & ht, quint8 & ho, quint8 & mt,
                    quint8 & mo, quint8 & st, quint8 & so);
    bool isRunning() const;

protected:

signals:
    virtual void notify();
    
public slots:
    void startTimer();
    void stopTimer();
    void timerComplete();
    void changeState(bool dir);

private:
    ViewMode _currentState;
    QTimer * _timer;
    bool _running;
    QTime _curTime;
    static QMutex _mutex;

    explicit ClockModel(QObject *parent = 0);
    ClockModel(const ClockModel &);
    ClockModel & operator=(const ClockModel &);

};

#endif // CLOCKMODEL_H
