#ifndef WIDGETSTRATEGY_H
#define WIDGETSTRATEGY_H

#include "buildstrategy.h"
#include <QMutex>

class widgetStrategy : public buildStrategy
{

public:
    widgetStrategy(tabPage *);
    virtual ~widgetStrategy( );

    virtual void buildPage( );

private:
    mutable QMutex m_mutex;

};

#endif // WIDGETSTRATEGY_H
