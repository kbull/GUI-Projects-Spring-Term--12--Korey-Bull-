#include "panelpage.h"

panelPage::panelPage(QWidget * parent)
    : tabPage(parent), m_split(0), m_img(0),
      m_larea(0), m_rarea(0), m_tabw(0), m_disc(0)
{

}


panelPage::~panelPage( )
{

}


void panelPage::initializePage(const KitchenSink * sink)
{
    tabPage::performBasicSetup(PANEL);

    m_split = new QSplitter(Qt::Horizontal, this);
    m_disc = new QCommandLinkButton("Disclose something:", this);
    m_img = new QImage("toolboxIcon.png");
    m_tabw = new QTabWidget(this);
    m_larea = new QScrollArea;
    m_rarea = new QScrollArea;

    // layout additional elements

    // set the main layout
    setLayout(tabPage::m_pageLayout);
    setStyleSheet(SinkModel::getInstance().getStyleSheet(PANEL));
}


Tabs panelPage::getTabKey( ) const
{
    return PANEL;
}
