#include "binaryview.h"
#include "Enumerations.h"
#include <QPainter>

#define RD 70.0
#define RY 23.0
#define RX 13.0
#define ALEN 5760


BinaryView::BinaryView(QWidget *parent) :
    QWidget(parent), _ht(0), _ho(0), _mt(0), _mo(0), _st(0), _so(0),
    _onClr(207, 0, 0, 207), _offClr(109, 34, 0, 179)
{
    setBaseSize(VIEW_WIDTH, VIEW_HEIGHT);
    setMaximumSize(VIEW_WIDTH, VIEW_HEIGHT);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}


BinaryView::~BinaryView()
{

}


void BinaryView::updateState(quint8 * data, quint8 size)
{
    if (data && size == BCD_CNT)
    {
        _ht = data[5];
        _ho = data[4];
        _mt = data[3];
        _mo = data[2];
        _st = data[1];
        _so = data[0];


        QWidget::update();
    }
}


void BinaryView::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    QColor bgClr(0, 0, 0);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.scale(1.0, 1.0);

    painter.setPen(Qt::NoPen);
    painter.setBrush(bgClr);

    painter.save();
    painter.drawRect(0, 0, VIEW_WIDTH, VIEW_HEIGHT);
    painter.rotate();

    drawHours(painter);
    drawMinutes(painter);
    drawSeconds(painter);

}


void BinaryView::drawHours(QPainter painter)
{
    QRectF htr[2] = {QRectF(RX, RY, RD, RD),
                     QRectF(RX, 163.0, RD, RD)};

    QRectF hor[3] = {QRectF(RX, RY, RD, RD),
                     QRectF(RX, 163.0, RD, RD),
                     QRectF(RX, 313.0, RD, RD)};

    painter.setPen(Qt::NoPen);

    if (_ht)
        painter.setBrush(_onClr);
    else
        painter.setBrush(_offClr);

    // draw hours - ten's col leds
    for (int i = 0; i < 2; ++i)
    {
        if (i)
            painter.setBrush(_offClr);

        painter.save();
        painter.drawArc(htr[i], 0, ALEN);
        painter.restore();
    }

    for (int i = 0; i < 3; ++i)
    {
        switch (i)
        {
        case 0:
            if (_ho & 0x01)
                painter.setBrush(_onClr);
            else
                painter.setBrush(_offClr);

            break;
        case 1:
            if (_ho & 0x02)
                painter.setBrush(_onClr);
            else
                painter.setBrush(_offClr);

            break;

        case 2:
            if (_ho & 0x04)
                painter.setBrush(_onClr);
            else
                painter.setBrush(_offClr);

            break;
        }

        painter.save();
        painter.drawArc(hor[i], 0, ALEN);
        painter.restore();
    }
}


void BinaryView::drawMinutes(QPainter painter)
{
    QRectF mtr[3] = { QRectF(RX + 76.0, RY, RD, RD),
                      QRectF(RX + 76.0, 163.0, RD, RD),
                      QRectF(RX + 76.0, 313.0, RD, RD)};

    QRectF mor[4] = { QRectF(228.0, RY, RD, RD),
                      QRectF(228.0, 163.0, RD, RD),
                      QRectF(228.0, 313.0, RD, RD),
                      QRectF(228.0, 463.0, RD, RD)};

    painter.setPen(Qt::NoPen);

    // paint minutes 10 col led
    for (int i = 0, arg = 0x01; i < 3; ++i, arg <<= 1)
    {
        if (_mt & arg)
            painter.setBrush(_onClr);
        else
            painter.setBrush(_offClr);

        painter.save();
        painter.drawArc(mtr[i], 0, ALEN);
        painter.save();
    }

    for (int i = 0, arg = 0x01; i < 4; ++i, arg <<= 1)
    {
        if (_mo & arg)
            painter.setBrush(_onClr);
        else
            painter.setBrush(_offClr);

        painter.save();
        painter.drawArc(mor[i], 0, ALEN);
        painter.save();
    }
}


void BinaryView::drawSeconds(QPainter painter)
{
    QRectF str[3] = { QRectF(304.0, RY, RD, RD),
                      QRectF(304.0, 163.0, RD, RD),
                      QRectF(304.0, 313.0, RD, RD)};

    QRectF sor[4] = { QRectF(380.0, RY, RD, RD),
                      QRectF(380.0, 163.0, RD, RD),
                      QRectF(380.0, 313.0, RD, RD),
                      QRectF(380.0, 463.0, RD, RD)};

    painter.setPen(Qt::NoPen);

    // paint minutes 10 col led
    for (int i = 0, arg = 0x01; i < 3; ++i, arg <<= 1)
    {
        if (_st & arg)
            painter.setBrush(_onClr);
        else
            painter.setBrush(_offClr);

        painter.save();
        painter.drawArc(str[i], 0, ALEN);
        painter.save();
    }

    for (int i = 0, arg = 0x01; i < 4; ++i, arg <<= 1)
    {
        if (_so & arg)
            painter.setBrush(_onClr);
        else
            painter.setBrush(_offClr);

        painter.save();
        painter.drawArc(sor[i], 0, ALEN);
        painter.save();
    }
}
