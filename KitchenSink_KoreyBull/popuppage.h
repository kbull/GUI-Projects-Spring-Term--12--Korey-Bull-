#ifndef POPUPPAGE_H
#define POPUPPAGE_H

#include "tabpage.h"
#include <QPushButton>
#include <QComboBox>

class popupPage : public tabPage
{
public:
    popupPage(QWidget * parent = 0);
    virtual ~popupPage( );

    virtual void initializePage( );
    virtual Tabs getTabKey( ) const;

signals:

public slots:
    void popupPressed( );
    void dialogPressed( );

protected:

private:
    QPushButton * m_popup;
    QPushButton * m_dialog;
    QComboBox * m_list;

    void populateList( );

};

#endif // POPUPPAGE_H
