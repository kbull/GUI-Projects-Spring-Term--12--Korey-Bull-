#include "clockviewfactory.h"

ClockViewFactory::ClockViewFactory()
{
}


ClockView * ClockViewFactory::CreateClockView(ViewMode key)
{
    ClockView * temp = 0;

    switch (key)
    {
     case ANALOG:
        break;

     case DIGITAL:
        break;

     case BINARY:
        break;

        default:
    }

    return temp;
}
