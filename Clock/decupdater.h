#ifndef DECUPDATER_H
#define DECUPDATER_H

#include "IUpdater.h"


class DecUpdater : public IUpdater
{
public:
    DecUpdater();
    virtual ~DecUpdater();

    virtual quint8 initData(quint8 *&);

private:
    DecUpdater(const DecUpdater &);
    DecUpdater & operator=(const DecUpdater &);

};

#endif // DECUPDATER_H
