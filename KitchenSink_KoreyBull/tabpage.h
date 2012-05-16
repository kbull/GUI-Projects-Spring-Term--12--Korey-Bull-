#ifndef TABPAGE_H
#define TABPAGE_H

#include <QWidget>
#include <QLabel>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include "Enumerations.h"
#include "sinkmodel.h"
#include "kitchensink.h"

class tabPage : public QWidget
{
    Q_OBJECT
public:
    explicit tabPage(QWidget *parent = 0);
    virtual ~tabPage( );

    virtual void initializePage(const KitchenSink *) = 0;
    virtual Tabs getTabKey( ) const = 0;
    
signals:
    
public slots:

protected:
    QFrame * m_textFrame;
    QLabel * m_text;
    QFormLayout * m_pageLayout;
    QHBoxLayout * m_hTextLayout;
    QSpacerItem * m_textSpacers[TXT_SPACERS];

    virtual void performBasicSetup(Tabs key);

private:
    virtual void instantiateBaseElements( );
    virtual void fillTextEdit(Tabs key);
    virtual void setupBasicLayout( );
    
};

#endif // TABPAGE_H
