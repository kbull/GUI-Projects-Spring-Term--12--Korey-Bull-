#include "analogview.h"
#include "Enumerations.h"


AnalogView::AnalogView(QWidget *parent) :
    QWidget(parent), _h(0), _m(0), _s(0)
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


void AnalogView::paintEvent(QPaintEvent *)
{

}
