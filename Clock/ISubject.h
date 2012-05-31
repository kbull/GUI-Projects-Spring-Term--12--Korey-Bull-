#ifndef ISUBJECT_H
#define ISUBJECT_H

#include <QWidget>


class ISubject
{
public:
    ~ISubject( )
    { }

    virtual void registerObserver(QWidget *) = 0;
    virtual void removeObserver(QWidget *) = 0;

signals:
    virtual void notify() = 0;

protected:
    ISubject( )
    { }

private:


};

#endif // ISUBJECT_H
