#include "multiton.h"
#include "tabbuilder.h"
#include "intropage.h"
#include "panelpage.h"
#include "widgetpage.h"
#include "popuppage.h"
#include "textpage.h"
#include "listpage.h"


Multiton::Multiton()
{
}

tabPage * Multiton::getPage(Tabs key)
{
    tabPage * temp = 0;

    if (key < INTRO || key > POPUP)
        return temp;

    m_mutex.lock();

    if (m_tabPages.contains(key))
        temp = m_tabPages[key];

    m_mutex.unlock();

    return temp;
}


void Multiton::loadPages( )
{
    const char * tabStrs[] = {
                                 "Intro",
                                 "Widgets",
                                 "Panels",
                                 "Lists",
                                 "Text",
                                 "Popups"
                               };
    tabPage * temp = 0;
    bool loaded = false;

    m_mutex.lock();

    for (Tabs i = INTRO; !loaded;)
    {
        switch (i)
        {
        case INTRO:
            temp = new introPage;
            temp->setObjectName(tabStrs[i]);
            m_tabPages[i] = temp;

            i = WIDGET;
            break;

        case WIDGET:
            temp = new widgetPage;
            temp->setObjectName(tabStrs[i]);
            m_tabPages[i] = temp;

            i = PANEL;
            break;

        case PANEL:
            temp = new panelPage;
            temp->setObjectName(tabStrs[i]);
            m_tabPages[i] = temp;

            i = LIST;
            break;

        case LIST:
            temp = new listPage;
            temp->setObjectName(tabStrs[i]);
            m_tabPages[i] = temp;

            i = TEXT;
            break;

        case TEXT:
            temp = new textPage;
            temp->setObjectName(tabStrs[i]);
            m_tabPages[i] = temp;

            i = POPUP;
            break;

        case POPUP:
            temp = new popupPage;
            temp->setObjectName(tabStrs[i]);
            m_tabPages[i] = temp;

            loaded = true;
            break;

        default :
            loaded = true;

        }
    }

    m_mutex.unlock();
}


Multiton & Multiton::getInstance( )
{
    static Multiton reference;

    return reference;
}
