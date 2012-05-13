#include "pagebuilder.h"
#include "introstrategy.h"
#include "widgetstrategy.h"
#include "panelstrategy.h"
#include "popupstrategy.h"
#include "textstrategy.h"
#include "liststrategy.h"
#include "tabbuilder.h"
#include "multiton.h"


pageBuilder::pageBuilder(QObject * parent)
    : QObject(parent), m_threadCount(0)
{
    Multiton::getInstance().loadPages();

    for (int i = 0; i < NUM_TABS; ++i)
    {
        m_pages[i] = new tabBuilder;
        connect(m_pages[i], SIGNAL(finished()), this, SLOT(threadFinished()));

        switch(i)
        {
        case INTRO:
            m_builders[i] = new introStrategy(Multiton::getInstance().getPage(INTRO));
            m_pages[i]->setBuildStrategy(m_builders[i]);
            break;

        case WIDGET:
            m_builders[i] = new widgetStrategy(Multiton::getInstance().getPage(WIDGET));
            m_pages[i]->setBuildStrategy(m_builders[i]);
            break;

        case PANEL:
            m_builders[i] = new panelStrategy(Multiton::getInstance().getPage(PANEL));
            m_pages[i]->setBuildStrategy(m_builders[i]);
            break;

        case LIST:
            m_builders[i] = new listStrategy(Multiton::getInstance().getPage(LIST));
            m_pages[i]->setBuildStrategy(m_builders[i]);
            break;

        case TEXT:
            m_builders[i] = new textStrategy(Multiton::getInstance().getPage(TEXT));
            m_pages[i]->setBuildStrategy(m_builders[i]);
            break;

        case POPUP:
            m_builders[i] = new popupStrategy(Multiton::getInstance().getPage(POPUP));
            m_pages[i]->setBuildStrategy(m_builders[i]);
            break;

        default :
            break;
        }
    }
}


pageBuilder::~pageBuilder()
{
    for (int i = 0; i < NUM_TABS; ++i)
    {
        delete m_pages[i];
        m_pages[i] = 0;

        delete m_builders[i];
        m_builders[i] = 0;
    }
}

void pageBuilder::spawnThreads( )
{
    for (int i = 0; i < NUM_TABS; ++i)
    {
        if (m_pages[i] != 0 && m_builders[i] != 0)
        {
            connect(m_pages[i], SIGNAL(finished()), this, SLOT(threadFinished()));
            m_pages[i]->start();
        }
    }
}


void pageBuilder::threadFinished( )
{
    QMutexLocker locker(&m_mutex);

    if (m_threadCount < NUM_TABS)
        ++m_threadCount;
    else
    {
        m_threadCount = 0;
        emit objectCreationFinished();
    }
}
