#include "listpage.h"

listPage::listPage(QWidget *parent)
    : tabPage(parent)
{
}


listPage::~listPage( )
{

}


void listPage::initializePage(const KitchenSink * sink)
{

    tabPage::performBasicSetup(LIST);

    // widget creation

    // settings / setup

    // layouts

    // connections and layout merging
    setLayout(tabPage::m_pageLayout);
    setStyleSheet(SinkModel::getInstance().getStyleSheet(LIST));
    // anything else?
}


Tabs listPage::getTabKey( ) const
{
    return LIST;
}
