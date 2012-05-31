#ifndef CLOCKVIEWFACTORY_H
#define CLOCKVIEWFACTORY_H

#include "clockview.h"
#include "Enumerations.h"

class ClockViewFactory
{

public:    
    ClockViewFactory();
    ~ClockViewFactory()
    { }

    ClockView * CreateClockView(ViewMode);

};

#endif // CLOCKVIEWFACTORY_H
