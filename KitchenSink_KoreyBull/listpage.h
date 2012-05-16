#ifndef LISTPAGE_H
#define LISTPAGE_H

#include "tabpage.h"
#include <QComboBox>
#include <QListView>
#include <QTreeView>
#include <QCompleter>



class listPage : public tabPage
{
public:
    listPage(QWidget * parent = 0);
    virtual ~listPage( );

    virtual void initializePage(const KitchenSink *);
    virtual Tabs getTabKey( ) const;

signals:

public slots:

private:

};

#endif // LISTPAGE_H
