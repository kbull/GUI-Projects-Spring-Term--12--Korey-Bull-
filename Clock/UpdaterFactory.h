#ifndef UPDATERFACTORY_H
#define UPDATERFACTORY_H

#include "bcdupdater.h"
#include "decupdater.h"

class UpdaterFactory
{
public:
    UpdaterFactory()
    { }

    ~UpdaterFactory()
    { }

    DecUpdater * createDec()
    {
        return new DecUpdater;
    }

    BCDUpdater * createBCD()
    {
        return new BCDUpdater;
    }

};

#endif // UPDATERFACTORY_H
