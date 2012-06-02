#ifndef ANALOGCONTROLLER_H
#define ANALOGCONTROLLER_H

#include "IController.h"
#include "clockview.h"


class AnalogController : public IController
{
    Q_OBJECT

public:
    AnalogController(ClockView *);
    virtual ~AnalogController( )
    { }

signals:

public slots:
    virtual void buttonPressEvent( );
    void timerEvent( );

private:
    ClockView * _view;

    AnalogController(const AnalogController &);
    AnalogController & operator=(const AnalogController &);

};

#endif // ANALOGCONTROLLER_H
