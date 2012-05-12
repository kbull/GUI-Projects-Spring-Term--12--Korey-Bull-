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
}


Tabs panelPage::getTabKey( ) const
{
    return PANEL;
}
