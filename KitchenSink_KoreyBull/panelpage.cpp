#include "panelpage.h"

panelPage::panelPage(QWidget * parent)
    : tabPage(parent)
{
}


panelPage::~panelPage( )
{

}


void panelPage::initializePage(const KitchenSink * sink)
{
    tabPage::performBasicSetup(PANEL);

    // layout additional elements

    // set the main layout
    setLayout(tabPage::m_pageLayout);
    setStyleSheet(SinkModel::getInstance().getStyleSheet(PANEL));
}


Tabs panelPage::getTabKey( ) const
{
    return PANEL;
}
