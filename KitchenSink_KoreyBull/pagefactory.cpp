#include "pagefactory.h"


introPage * PageFactory::createIntroPage(const KitchenSink * sink)
{
    introPage * temp = new introPage;

    temp->initializePage(sink);

    return temp;
}

widgetPage * PageFactory::createWidgetPage(const KitchenSink * sink)
{
    widgetPage * temp = new widgetPage;

    temp->initializePage(sink);

    return temp;
}

panelPage * PageFactory::createPanelPage(const KitchenSink * sink)
{
    panelPage * temp = new panelPage;

    temp->initializePage(sink);

    return temp;
}

listPage * PageFactory::createListPage(const KitchenSink * sink)
{
    listPage * temp = new listPage;

    temp->initializePage(sink);

    return temp;
}

textPage * PageFactory::createTextPage(const KitchenSink * sink)
{
    textPage * temp = new textPage;

    temp->initializePage(sink);

    return temp;
}

popupPage * PageFactory::createPopupPage(const KitchenSink * sink)
{
    popupPage * temp = new popupPage;

    temp->initializePage(sink);

    return temp;
}
