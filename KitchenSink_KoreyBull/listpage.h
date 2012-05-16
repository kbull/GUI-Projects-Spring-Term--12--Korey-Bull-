#ifndef LISTPAGE_H
#define LISTPAGE_H

#include "tabpage.h"
#include <QComboBox>
#include <QListWidget>
#include <QTreeWidget>
#include <QCompleter>
#include <QLineEdit>


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
    QComboBox * m_cbox;
    QListWidget * m_list;
    QLineEdit * m_suggest;
    QCompleter * m_complete;
    QTreeWidget * m_treew;

    void initTree( );

};

#endif // LISTPAGE_H
