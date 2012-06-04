#ifndef IUPDATER_H
#define IUPDATER_H

#include "clockview.h"


class IUpdater
{

public:
    ~IUpdater()
    { }

    virtual quint8 initData(quint8 *&) = 0;

private:
    IUpdater()
    { }

    IUpdater(const IUpdater &);
    IUpdater & operator=(const IUpdater &);

};

#endif // IUPDATER_H
