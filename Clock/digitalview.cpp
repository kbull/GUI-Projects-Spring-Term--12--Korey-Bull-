#include "digitalview.h"
#include "Enumerations.h"
#include <QPainter>


DigitalView::DigitalView(QWidget *parent) :
    QWidget(parent), _ht(0), _ho(0), _mt(0), _mo(0), _st(0), _so(0)
{
    setBaseSize(VIEW_WIDTH, VIEW_HEIGHT);
    setMaximumSize(VIEW_WIDTH, VIEW_HEIGHT);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}


DigitalView::~DigitalView()
{

}


void DigitalView::updateState(quint8 * data, quint8 size)
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


void DigitalView::paintEvent(QPaintEvent * event)
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

    drawNumber(painter, _ht, 10, 150);
    drawNumber(painter, _ho, 98, 150);

    drawColon(painter, 103, 210);

    drawNumber(painter, _mt, 143, 150);
    drawNumber(painter, _mo, 231, 150);

    drawColon(painter, 236, 210);

    drawNumber(painter, _st, 276, 150);
    drawNumber(painter, _so, 382, 150);
}


void DigitalView::drawNumber(QPainter painter, quint16 num, quint16 x, quint16 y)
{
    QColor numClr();

    painter.setPen(Qt::NoPen);
    painter.setBrush(numClr);
    painter.save();

    // draw the number
    switch (num)
    {
    case 0:

        break;
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:

        break;
    case 8:

        break;
    case 9:

        break;

    default:
        break;
    }

    painter.restore();
}


void DigitalView::drawColon(QPainter painter, quint16 bx, quint16 by)
{
    QColor numClr();

    painter.setPen(Qt::NoPen);
    painter.setBrush(numClr);

    bx += 5;
    by += 5;
    // paint colon
    painter.save();
    painter.drawArc(bx, by, 30, 30, 0, 5760);
    painter.restore();

    by += 30;
    painter.save();
    painter.drawArc(bx, by, 30, 30, 0, 5760);
    painter.restore();
}
