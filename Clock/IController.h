#ifndef ICONTROLLER_H
#define ICONTROLLER_H


class IController
{
public:
    ~IController( )
    { }

signals:


public slots:
    virtual void buttonPressEvent( ) = 0;


protected:
    explicit IController( )
    { }

private:
    IController(const IController &);
    IController & operator=(const IController &);

};

#endif // ICONTROLLER_H
