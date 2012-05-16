#ifndef PAGEFACTORY_H
#define PAGEFACTORY_H

#include "intropage.h"
#include "widgetpage.h"
#include "panelpage.h"
#include "listpage.h"
#include "textpage.h"
#include "popuppage.h"


class PageFactory
{
public:
    inline PageFactory() { }
    ~PageFactory() { }

    introPage * createIntroPage(const KitchenSink *);
    widgetPage * createWidgetPage(const KitchenSink *);
    panelPage * createPanelPage(const KitchenSink *);
    listPage * createListPage(const KitchenSink *);
    textPage * createTextPage(const KitchenSink *);
    popupPage * createPopupPage(const KitchenSink *);

private:

};

#endif // PAGEFACTORY_H
