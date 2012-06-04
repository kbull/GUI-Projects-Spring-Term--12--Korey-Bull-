#ifndef IUPDATER_H
#define IUPDATER_H

#include "clockview.h"


class IUpdater
{

public:
    ~IUpdater()
    { }

    virtual quint8 initData(quint8 *&) = 0;

protected:
    IUpdater()
    { }

private:


    IUpdater(const IUpdater &);
    IUpdater & operator=(const IUpdater &);

};

#endif // IUPDATER_H
