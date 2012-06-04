#ifndef CLOCKVIEW_H
#define CLOCKVIEW_H

#include <Qt>

class ClockView //ClockView abstract base class that defines Observer interface
{
    Q_OBJECT
public:
    ~ClockView( )
    { }

signals:
    
public slots:
    virtual void updateState(quint8 *, quint8) = 0;

protected:
    explicit ClockView( )
    { }

};

#endif // CLOCKVIEW_H
