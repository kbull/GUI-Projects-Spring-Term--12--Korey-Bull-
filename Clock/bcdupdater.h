#ifndef BCDUPDATER_H
#define BCDUPDATER_H

#include "IUpdater.h"


class BCDUpdater : public IUpdater
{
public:
    BCDUpdater();
    virtual ~BCDUpdater();

    virtual quint8 initData(quint8 *&);

private:
    BCDUpdater(const BCDUpdater &);
    BCDUpdater & operator=(const BCDUpdater &);

};

#endif // BCDUPDATER_H
