#include "intropage.h"


introPage::introPage(QWidget * parent)
    : tabPage(parent)
{
}


introPage::~introPage()
{
    // nothing extra
}


void introPage::initializePage( )
{
    tabPage::performBasicSetup("html/intro.html");

    QWidget::setLayout(tabPage::m_pageLayout);
}


Tabs introPage::getTabKey( ) const
{
    return INTRO;
}
