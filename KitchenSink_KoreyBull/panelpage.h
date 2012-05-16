#ifndef PANELPAGE_H
#define PANELPAGE_H

#include "tabpage.h"
#include <QSplitter>
#include <QTabWidget>
#include <QScrollArea>
#include <QCommandLinkButton>
#include <QImage>

class panelPage : public tabPage
{
public:
    panelPage(QWidget * parent = 0);
    virtual ~panelPage( );

    virtual void initializePage(const KitchenSink *);
    virtual Tabs getTabKey( ) const;

private:
    QSplitter * m_split;
    QScrollArea * m_larea;
    QScrollArea * m_rarea;
    QTabWidget * m_tabw;
    QCommandLinkButton * m_disc;
    QImage * m_img;
    // addtl elements
};

#endif // PANELPAGE_H
