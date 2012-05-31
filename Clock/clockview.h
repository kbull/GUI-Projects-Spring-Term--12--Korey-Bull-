#ifndef CLOCKVIEW_H
#define CLOCKVIEW_H


class ClockView //ClockView abstract base class that defines Observer interface
{
    Q_OBJECT

public:
    ~ClockView( )
    { }    

signals:
    
public slots:
    virtual void update( ) = 0;

protected:
    explicit ClockView( )
    { }

};

#endif // CLOCKVIEW_H
