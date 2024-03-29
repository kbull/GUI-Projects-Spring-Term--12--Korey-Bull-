#include "decupdater.h"
#include "clockmodel.h"


DecUpdater::DecUpdater()
{
}


DecUpdater::~DecUpdater()
{

}


quint8 DecUpdater::initData(quint8 *& data)
{
    quint8 size = 0;

    if (data)
    {
        data = new quint8[size = 3];

        ClockModel::getInstance().getDecimalTime(data[2], data[1], data[0]);
    }

    return size;
}
