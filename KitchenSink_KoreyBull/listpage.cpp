#include "listpage.h"

listPage::listPage(QWidget *parent)
    : tabPage(parent)
{
}


listPage::~listPage( )
{

}


void listPage::initializePage( )
{

    tabPage::performBasicSetup("html/list.html");

    // widget creation

    // settings / setup

    // layouts

    // connections and layout merging
    setLayout(tabPage::m_pageLayout);
    // anything else?
}


Tabs listPage::getTabKey( ) const
{
    return LIST;
}
