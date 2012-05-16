#ifndef PANELPAGE_H
#define PANELPAGE_H

#include "tabpage.h"


class panelPage : public tabPage
{
public:
    panelPage(QWidget * parent = 0);
    virtual ~panelPage( );

    virtual void initializePage(const KitchenSink *);
    virtual Tabs getTabKey( ) const;

private:

    // addtl elements
};

#endif // PANELPAGE_H
