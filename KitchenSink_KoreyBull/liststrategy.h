#ifndef LISTSTRATEGY_H
#define LISTSTRATEGY_H

#include "buildstrategy.h"


class listStrategy : public buildStrategy
{
public:
    listStrategy(tabPage *);
    virtual ~listStrategy( );

    virtual void buildPage( );

private:

};

#endif // LISTSTRATEGY_H
