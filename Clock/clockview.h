#ifndef CLOCKVIEW_H
#define CLOCKVIEW_H

#include <QWidget>

class ClockView : public QWidget //ClockView abstract base class that defines Observer interface
{
    Q_OBJECT
public:
    ~ClockView( )
    { }

signals:
    
public slots:
    virtual void updateState(quint8 *, quint8) = 0;

protected:
    explicit ClockView(QWidget * parent = 0)
        : QWidget(parent)
    { }

};

#endif // CLOCKVIEW_H
