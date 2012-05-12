#ifndef TABPAGE_H
#define TABPAGE_H

#include <QWidget>
#include <QLabel>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include "Enumerations.h"



class tabPage : public QWidget
{
    Q_OBJECT
public:
    explicit tabPage(QWidget *parent = 0);
    virtual ~tabPage( );

    virtual void initializePage( ) = 0;
    virtual Tabs getTabKey( ) const = 0;
    
signals:
    void popup( );
    void dialog( );
    void menuDialog( );
    
public slots:
    void popupPressed( );
    void dialogPressed( );
    void menuAction();

protected:
    QFrame * m_textFrame;
    QLabel * m_text;
    QFormLayout * m_pageLayout;
    QHBoxLayout * m_hTextLayout;
    QSpacerItem * m_textSpacers[TXT_SPACERS];

    virtual void performBasicSetup(QString txtFile);

private:
    virtual void instantiateBaseElements( );
    virtual void fillTextEdit(QString fileLoc);
    virtual void setupBasicLayout( );
    
};

#endif // TABPAGE_H
