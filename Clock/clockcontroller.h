#ifndef CLOCKCONTROLLER_H
#define CLOCKCONTROLLER_H

#include "IController.h"
#include "clockview.h"


class ClockController : public IController
{
    Q_OBJECT

public:
    ClockController(ClockView *);

signals:

public slots:
    virtual void buttonPressEvent( );

private:
    ClockView * _view;

    ClockController(const ClockController &);
    ClockController & operator=(const ClockController &);

};

#endif // CLOCKCONTROLLER_H
