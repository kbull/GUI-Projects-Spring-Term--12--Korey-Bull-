#include "textstrategy.h"
#include "textpage.h"


textStrategy::textStrategy(tabPage * page)
    : buildStrategy(page)
{
}


textStrategy::~textStrategy( )
{

}


void textStrategy::buildPage( )
{
    textPage * temp = 0;

    temp = dynamic_cast<textPage *>(buildStrategy::m_page);

    if (temp != 0)
        temp->initializePage();
}
