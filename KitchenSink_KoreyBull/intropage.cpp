#include "intropage.h"


introPage::introPage(QWidget * parent)
    : tabPage(parent)
{
}


introPage::~introPage()
{
    // nothing extra
}


void introPage::initializePage(const KitchenSink * sink)
{
    tabPage::performBasicSetup(INTRO);

    QWidget::setLayout(tabPage::m_pageLayout);

    setStyleSheet(SinkModel::getInstance().getStyleSheet(INTRO));

}


Tabs introPage::getTabKey( ) const
{
    return INTRO;
}
