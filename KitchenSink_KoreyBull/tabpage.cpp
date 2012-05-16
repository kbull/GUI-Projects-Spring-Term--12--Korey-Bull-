#include "tabpage.h"
#include <QFile>
#include <QTextStream>


tabPage::tabPage(QWidget *parent) :
    QWidget(parent), m_textFrame(0), m_text(0),
    m_pageLayout(0), m_hTextLayout(0)
{
    for (short i = 0; i < TXT_SPACERS; ++i)
    {
        m_textSpacers[i] = 0;
    }
}


tabPage::~tabPage( )
{
    delete m_textFrame;
    m_textFrame = 0;

    delete m_text;
    m_text = 0;

    delete m_hTextLayout;
    m_hTextLayout = 0;

    delete m_pageLayout;
    m_pageLayout = 0;
}


void tabPage::performBasicSetup(Tabs key)
{
    instantiateBaseElements();
    fillTextEdit(key);
    setupBasicLayout();

    m_textFrame->setObjectName(SinkModel::getInstance().getTabLabel(key) + "Frame");
}


void tabPage::instantiateBaseElements( )
{
    m_text = new QLabel;
    m_textFrame = new QFrame;
    m_pageLayout = new QFormLayout;
    m_hTextLayout = new QHBoxLayout;

    for (short i = 0; i < TXT_SPACERS; ++i)
    {
        if (i == LEFT_SP)
        {
            m_textSpacers[i] = new QSpacerItem(40, 130);
        }
        else if (i == RIGHT_SP)
        {
            m_textSpacers[i] = new QSpacerItem(10, 130);
        }
        else // top & bottom
        {
            m_textSpacers[i] = new QSpacerItem(130, 10);
        }
    }

}


void tabPage::fillTextEdit(Tabs key)
{
    if ((key >= INTRO) && (key <= POPUP))
    {
        m_text->setTextFormat(Qt::RichText);
        m_text->setText(SinkModel::getInstance().getPageText(key));
        m_text->setWordWrap(true);
    }
}


void tabPage::setupBasicLayout( )
{
    //create horizontal layout
    m_hTextLayout->addItem(m_textSpacers[LEFT_SP]);
    m_hTextLayout->addWidget(m_text);
    m_hTextLayout->addItem(m_textSpacers[RIGHT_SP]);

    // create form layout
    m_pageLayout->addItem(m_textSpacers[TOP_SP]);
    m_pageLayout->addRow(m_hTextLayout);
    m_pageLayout->addItem(m_textSpacers[BOT_SP]);
}
