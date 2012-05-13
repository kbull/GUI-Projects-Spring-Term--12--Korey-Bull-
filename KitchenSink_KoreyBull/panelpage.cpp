#include "panelpage.h"

panelPage::panelPage(QWidget * parent)
    : tabPage(parent)
{
}


panelPage::~panelPage( )
{

}


void panelPage::initializePage( )
{
    tabPage::performBasicSetup("html/panel.html");

    // layout additional elements

    // set the main layout
    setLayout(tabPage::m_pageLayout);
}


Tabs panelPage::getTabKey( ) const
{
    return PANEL;
}
