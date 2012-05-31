#ifndef CLOCKVIEW_H
#define CLOCKVIEW_H

#include <QWidget>

class ClockView : public QWidget
{
    Q_OBJECT
public:
    explicit ClockView(QWidget *parent = 0);
    virtual ~ClockView();

    virtual void update( ) = 0;

signals:
    
public slots:
    
};

#endif // CLOCKVIEW_H
