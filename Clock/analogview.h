#ifndef ANALOGVIEW_H
#define ANALOGVIEW_H

#include "clockview.h"

class AnalogView : public ClockView
{
    Q_OBJECT
public:
    explicit AnalogView(QWidget *parent = 0);
    virtual ~AnalogView();
    
signals:
    
public slots:
    virtual void updateState(quint8 * data, quint8 size);
    void paintEvent(QPaintEvent *);

private:
    quint8 _h, _m, _s;
    
};

#endif // ANALOGVIEW_H
