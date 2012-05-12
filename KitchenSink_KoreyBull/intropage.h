#ifndef INTROPAGE_H
#define INTROPAGE_H

#include "tabpage.h"


class introPage : public tabPage
{
public:
    introPage(QWidget * parent = 0);
    virtual ~introPage( );

    virtual void initializePage( );
    virtual Tabs getTabKey( ) const;

signals:

public slots:

private:


};

#endif // INTROPAGE_H
