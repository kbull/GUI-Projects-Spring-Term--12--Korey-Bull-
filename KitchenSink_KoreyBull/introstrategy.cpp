#include "introstrategy.h"

#include "intropage.h"

introStrategy::introStrategy(tabPage * page)
    : buildStrategy(page)
{

}


introStrategy::~introStrategy( )
{

}


void introStrategy::buildPage( )
{
    QMutexLocker locker(&m_mutex);
    introPage * page = 0;

    page = dynamic_cast<introPage *>(buildStrategy::m_page);

    page->initializePage();
}
