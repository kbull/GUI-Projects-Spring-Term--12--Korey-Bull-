#include "popupstrategy.h"
#include "popuppage.h"

popupStrategy::popupStrategy(tabPage * page)
    : buildStrategy(page)
{
}


popupStrategy::~popupStrategy()
{

}


void popupStrategy::buildPage()
{
    QMutexLocker locker(&m_mutex);

    popupPage * page = 0;

    page = dynamic_cast<popupPage *>(buildStrategy::m_page);

    page->initializePage();
}
