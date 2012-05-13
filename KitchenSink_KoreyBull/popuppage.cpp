#include "popuppage.h"
#include <QImage>


popupPage::popupPage(QWidget * parent)
    : tabPage(parent), m_popup(0), m_dialog(0), m_list(0)
{
}


popupPage::~popupPage( )
{
    delete m_popup;
    m_popup = 0;

    delete m_dialog;
    m_dialog = 0;

    delete m_list;
    m_list = 0;
}


void popupPage::initializePage( )
{
    QVBoxLayout * layout = new QVBoxLayout;
    tabPage::performBasicSetup("html/popup.html");

    m_popup = new QPushButton("Show Popup");
    m_dialog = new QPushButton("Show Dialog");
    m_list = new QComboBox;

    populateList( );

    // setup layout here
    layout->addWidget(m_popup, 0, Qt::AlignCenter);
    layout->addWidget(m_dialog, 0, Qt::AlignCenter);
    layout->addWidget(m_list, 0, Qt::AlignCenter);


    tabPage::m_pageLayout->addRow(layout);
    setLayout(tabPage::m_pageLayout);

    connect(m_popup, SIGNAL(clicked()), this, SLOT(popupPressed()));
    connect(m_dialog, SIGNAL(clicked()), this, SLOT(dialogPressed()));
}


Tabs popupPage::getTabKey( ) const
{
    return POPUP;
}


void popupPage::populateList( )
{
    QString temp = "list item %1";

    m_list->setMaxCount(10);
    m_list->setMaxVisibleItems(10);

    for (short i = 0; i < 10; ++i)
        m_list->addItem(temp.arg(i));
}
