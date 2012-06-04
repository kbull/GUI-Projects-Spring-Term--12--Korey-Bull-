#include "bcdupdater.h"
#include "clockmodel.h"

BCDUpdater::BCDUpdater()
{
}


BCDUpdater::~BCDUpdater()
{

}


quint8 BCDUpdater::updateView(quint8 *& data)
{
    quint8 size = 0;

    if (!data)
    {        
        data = new quint8[size = 6];

        ClockModel::getInstance().getBCDTime(data[5], data[4], data[3],
                                             data[2], data[1], data[0]);
    }

    return size;
}
