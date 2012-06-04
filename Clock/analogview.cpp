#include "analogview.h"
#include "Enumerations.h"
#include <QPainter>


AnalogView::AnalogView(QWidget *parent) :
    ClockView(parent), _h(0), _m(0), _s(0)
{
    setBaseSize(VIEW_WIDTH, VIEW_HEIGHT);
    setMaximumSize(VIEW_WIDTH, VIEW_HEIGHT);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}


AnalogView::~AnalogView()
{

}


void AnalogView::updateState(quint8 *data, quint8 size)
{
    if (data && size == DEC_CNT)
    {
        _s = data[0];

        _m = data[1];

        _h = data[2];

        QWidget::update();
    }
}


void AnalogView::paintEvent(QPaintEvent * event)
{
    const QPoint hourHand[3] = { QPoint(7, 8), QPoint(-7, 8), QPoint(0, -40)};
    const QPoint minuteHand[3] = { QPoint(7, 8), QPoint(-7, 8), QPoint(0, -70)};
    const QPoint secondHand[3] = { QPoint(7, 8), QPoint(-7, 8), QPoint(0, -90)};
    QColor hColor(127, 0, 127);
    QColor mColor(0, 127, 127, 191);
    QColor sColor(127, 127, 0, 200);
    int side = VIEW_WIDTH;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);

    painter.setPen(Qt::NoPen);
    painter.setBrush(hColor);

    painter.save();
    painter.rotate(30.0 * ((_h + _m) / 60.0));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();

    painter.setPen(hColor);

    for (int i = 0; i < 12; ++i)
    {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(mColor);

    painter.save();
    painter.rotate(6.0 * ((_m + _s) / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    painter.setPen(mColor);

    for (int j = 0; j < 60; ++j)
    {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);

        painter.rotate(6.0);
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(sColor);

    painter.save();
    painter.rotate();
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();
}
