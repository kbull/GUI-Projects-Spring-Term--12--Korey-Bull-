#ifndef KITCHENSINK_H
#define KITCHENSINK_H

#include <QMainWindow>
#include <QMutex>
#include "sinkmodel.h"
#include "filereader.h"


namespace Ui {
class KitchenSink;
}

class KitchenSink : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit KitchenSink(QWidget *parent = 0);
    virtual ~KitchenSink();

    void startObjectCreation( );


public slots:
    void objectCreationFinished();

    // popup panel slots
    void popupPressed();
    void dialogPressed();

    //widget panel slots
    void menuActionDialog( );
    
private:
    Ui::KitchenSink *ui;
    FileReader * m_reader;
    mutable QMutex m_mutex;

    void connectEvents( );
    void setUpMainWindow( );

};

#endif // KITCHENSINK_H
