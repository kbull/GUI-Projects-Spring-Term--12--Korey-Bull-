#ifndef VIEWFACTORY_H
#define VIEWFACTORY_H

#include "digitalview.h"
#include "analogview.h"
#include "binaryview.h"

class ViewFactory
{
public:
    ViewFactory( )
    { }

    ~ViewFactory( )
    { }

    DigitalView * createDigitalView()
    {
        return new DigitalView;
    }

    AnalogView * createAnalogView()
    {
        return new AnalogView;
    }

    BinaryView * createBinaryView()
    {
        return new BinaryView;
    }

};

#endif // VIEWFACTORY_H
