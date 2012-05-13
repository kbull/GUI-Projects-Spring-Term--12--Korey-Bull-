#ifndef PANELSTRATEGY_H
#define PANELSTRATEGY_H

#include "buildstrategy.h"
#include <QMutex>

class panelStrategy : public buildStrategy
{
public:
    panelStrategy(tabPage * page);
    virtual ~panelStrategy( );

    virtual void buildPage( );

private:
    mutable QMutex m_mutex;
};

#endif // PANELSTRATEGY_H
