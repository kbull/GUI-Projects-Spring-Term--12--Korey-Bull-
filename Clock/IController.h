#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include "Enumerations.h"
#include "clockview.h"

class IController
{
    Q_OBJECT
public:
    ~IController( )
    { }

    virtual void forceViewUpdate() = 0;
    virtual void registerView(ClockView *) = 0;

signals:
    virtual void supplyNewData(quint8 *, quint8) = 0;

public slots:
    virtual void updateModel(ViewMode ) = 0;
    virtual void updateViewData() = 0;


protected:
    explicit IController( )
    { }

private:
    IController(const IController &);
    IController & operator=(const IController &);

};

#endif // ICONTROLLER_H
