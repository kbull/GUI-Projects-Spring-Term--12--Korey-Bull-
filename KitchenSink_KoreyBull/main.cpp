/******************************************************************************
* Author : Korey Bull
* Date Created : 5/6/2012
* Project Title : Lab 1 - Google Kitchen Sink w/ Qt
* Course/Term : CST 238 / Spring 2012
*
* Summary :
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
******************************************************************************/
#include <QtGui/QApplication>
#include "kitchensink.h"
#include "sinkmodel.h"
#include "filereader.h"
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    KitchenSink w;

    w.initKitchenSink();

    w.show();
    
    return a.exec();
}
