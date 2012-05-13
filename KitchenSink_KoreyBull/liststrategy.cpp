#include "liststrategy.h"
#include "listpage.h"



listStrategy::listStrategy(tabPage * page)
    : buildStrategy(page)
{
}


listStrategy::~listStrategy( )
{

}


void listStrategy::buildPage( )
{
    listPage * temp = 0;

    temp = dynamic_cast<listPage *>(buildStrategy::m_page);

    if (temp != 0)
        temp->initializePage( );

}
