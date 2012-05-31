#ifndef ISUBJECT_H
#define ISUBJECT_H

#include "IObserver.h"


class ISubject
{
public:
    ~ISubject( )
    { }

signals:
    virtual void notify() = 0;

protected:
    ISubject( )
    { }

private:


};

#endif // ISUBJECT_H
