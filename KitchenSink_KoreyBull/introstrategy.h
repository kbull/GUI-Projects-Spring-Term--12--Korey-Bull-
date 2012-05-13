#ifndef INTROSTRATEGY_H
#define INTROSTRATEGY_H

#include "buildstrategy.h"
#include <QMutex>


class introStrategy : public buildStrategy
{
public:
    introStrategy(tabPage *);
    virtual ~introStrategy( );

    virtual void buildPage( );

private:
    introStrategy(const introStrategy &);
    introStrategy & operator=(const introStrategy &);

    mutable QMutex m_mutex;

};

#endif // INTROSTRATEGY_H
