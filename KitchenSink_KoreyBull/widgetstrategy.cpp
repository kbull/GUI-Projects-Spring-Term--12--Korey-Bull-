#include "widgetstrategy.h"
#include "widgetpage.h"



widgetStrategy::widgetStrategy(tabPage * page)
    : buildStrategy(page)
{
}


widgetStrategy::~widgetStrategy( )
{

}


void widgetStrategy::buildPage( )
{
    QMutexLocker locker(&m_mutex);
    widgetPage * page = 0;

    page = dynamic_cast<widgetPage *>(buildStrategy::m_page);

    page->initializePage();
}
