#ifndef TEXTSTRATEGY_H
#define TEXTSTRATEGY_H

#include "buildstrategy.h"
#include <QMutex>


class textStrategy : public buildStrategy
{
public:
    textStrategy(tabPage *);
    virtual ~textStrategy( );

    virtual void buildPage( );

private:
    mutable QMutex m_mutex;

};

#endif // TEXTSTRATEGY_H
