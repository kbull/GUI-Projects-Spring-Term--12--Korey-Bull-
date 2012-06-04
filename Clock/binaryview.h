#ifndef BINARYVIEW_H
#define BINARYVIEW_H

#include "clockview.h"


class BinaryView : public ClockView
{
    Q_OBJECT
public:
    explicit BinaryView(QWidget *parent = 0);
    virtual ~BinaryView();
    
signals:
    
public slots:
    virtual void updateState(quint8 *, quint8);

private:
    quint8 _ht, _ho;
    quint8 _mt, _mo;
    quint8 _st, _so;
    QColor _onClr, _offClr;
    
    void drawHours(QPainter);
    void drawMinutes(QPainter);
    void drawSeconds(QPainter);
};

#endif // BINARYVIEW_H
