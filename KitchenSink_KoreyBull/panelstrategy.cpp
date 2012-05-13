#include "panelstrategy.h"
#include "panelpage.h"


panelStrategy::panelStrategy(tabPage * page)
    : buildStrategy(page)
{
}


panelStrategy::~panelStrategy( )
{

}


void panelStrategy::buildPage( )
{
    QMutexLocker locker(&m_mutex);

    panelPage * page = 0;

    page = dynamic_cast<panelPage *>(buildStrategy::m_page);

    page->initializePage();
}
