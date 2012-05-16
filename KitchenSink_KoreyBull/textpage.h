#ifndef TEXTPAGE_H
#define TEXTPAGE_H

#include "tabpage.h"
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>


class textPage : public tabPage
{
public:
    textPage(QWidget * parent = 0);
    virtual ~textPage( );

    virtual void initializePage(const KitchenSink *);
    virtual Tabs getTabKey( ) const;

protected:

private:
    QLabel ** m_cursPos;
    QLabel ** m_labels;
    QLineEdit ** m_lineEdits;
    QTextEdit * m_textEditor;

    void instantiateWidgets(QHBoxLayout * textLay[]);
    void setupHLayouts(QHBoxLayout * textLay[]);

};

#endif // TEXTPAGE_H
