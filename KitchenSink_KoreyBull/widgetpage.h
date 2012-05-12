#ifndef WIDGETPAGE_H
#define WIDGETPAGE_H

#include <QMenuBar>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QIcon>
#include "tabpage.h"


class widgetPage : public tabPage
{
public:
    widgetPage(QWidget * parent = 0);
    virtual ~widgetPage( );

    virtual void initializePage( );
    virtual Tabs getTabKey( ) const;


private:
    static const int BUTTONS = 4;
    QMenuBar * m_menu;
    QPushButton * m_pushButtons[BUTTONS];
    QCheckBox * m_enabledCheck;
    QCheckBox * m_disabledCheck;
    QRadioButton * m_choices[BUTTONS];
    QIcon m_icon2;
    QIcon m_icon3;

    void initializeMenu( );
    void initializeOpts( );

};

#endif // WIDGETPAGE_H
