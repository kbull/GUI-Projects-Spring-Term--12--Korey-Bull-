#ifndef CLOCKCONTROLLER_H
#define CLOCKCONTROLLER_H

#include "IController.h"
#include <QMutex>
#include <QThread>
#include <QObject>

class ClockController : public QObject, public IController
{
    Q_OBJECT
public:
    explicit ClockController(QObject * parent = 0);
    virtual ~ClockController();

    virtual void forceViewUpdate();
    virtual void registerView(ClockView * view);

signals:
    virtual void supplyNewData(quint8 * data, quint8 size);

public slots:
    virtual void updateModel(bool dir);
    virtual void updateViewData();

protected:

private:
    ClockView * _cView;
    QThread * _modelT;
    mutable QMutex _mutex;

};

#endif // CLOCKCONTROLLER_H
