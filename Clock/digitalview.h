#ifndef DIGITALVIEW_H
#define DIGITALVIEW_H

#include "clockview.h"


class DigitalView : public ClockView
{
    Q_OBJECT
public:
    explicit DigitalView(QWidget *parent = 0);
    virtual ~DigitalView();
    
signals:
    
public slots:
    virtual void updateState(quint8 *, quint8);
    void paintEvent(QPaintEvent *);

private:
    quint8 _ht, _ho;
    quint8 _mt, _mo;
    quint8 _st, _so;
    
    void drawNumber(QPainter, quint16, quint16, quint16);
    void drawColon(QPainter, quint16, quint16);
};

#endif // DIGITALVIEW_H
