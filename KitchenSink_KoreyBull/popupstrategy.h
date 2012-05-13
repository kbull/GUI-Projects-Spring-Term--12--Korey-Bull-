#ifndef POPUPSTRATEGY_H
#define POPUPSTRATEGY_H

#include <QMutex>
#include "buildstrategy.h"

class popupStrategy : public buildStrategy
{
public:
    popupStrategy(tabPage * page);
    virtual ~popupStrategy( );

    virtual void buildPage( );

private:
    mutable QMutex m_mutex;

};

#endif // POPUPSTRATEGY_H
