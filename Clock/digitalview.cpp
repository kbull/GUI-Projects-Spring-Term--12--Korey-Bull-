#include "digitalview.h"
#include "Enumerations.h"


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

        QWidget::update();
    }
}


void DigitalView::paintEvent(QPaintEvent * event)
{

}
