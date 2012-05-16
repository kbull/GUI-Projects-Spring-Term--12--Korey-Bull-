#ifndef WIDGETPAGE_H
#define WIDGETPAGE_H

#include <QMenuBar>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include "tabpage.h"

#define BUTTONS 4

class widgetPage : public tabPage
{
public:
    widgetPage(QWidget * parent = 0);
    virtual ~widgetPage( );

    virtual void initializePage(const KitchenSink *);
    virtual Tabs getTabKey( ) const;

public slots:

signals:

private:
    QMenuBar * m_menu;
    QPushButton * m_pushButtons[BUTTONS];
    QCheckBox * m_enabledCheck;
    QCheckBox * m_disabledCheck;
    QRadioButton * m_choices[BUTTONS];

    void initializeMenu( );
    void initializeOpts( );

};

#endif // WIDGETPAGE_H
