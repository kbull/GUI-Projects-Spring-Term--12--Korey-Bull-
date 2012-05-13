#ifndef MULTITON_H
#define MULTITON_H

#include <QMap>
#include <QMutex>
#include "intropage.h"
#include "panelpage.h"
#include "widgetpage.h"
#include "popuppage.h"
#include "textpage.h"
#include "listpage.h"

class Multiton
{
public:
    ~Multiton() { }

    tabPage * getPage(Tabs key);

    void loadPages( );

    static Multiton & getInstance();

protected:
    Multiton();


private:
    Multiton(const Multiton &);
    Multiton & operator=(const Multiton &);

    QMap<Tabs, tabPage *> m_tabPages;
    QMutex m_mutex;
};

#endif // MULTITON_H
