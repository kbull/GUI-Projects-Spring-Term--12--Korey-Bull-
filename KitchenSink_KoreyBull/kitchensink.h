#ifndef KITCHENSINK_H
#define KITCHENSINK_H

#include <QMainWindow>
#include <QLabel>
#include "pagebuilder.h"

namespace Ui {
class KitchenSink;
}

class KitchenSink : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit KitchenSink(QWidget *parent = 0);
    ~KitchenSink();

    void startObjectCreation( );
    void setUpMainWindow( );

    bool areThreadsFinished() const;

public slots:
    void objectCreationFinished();

    // popup panel slots
    void popupPressed();
    void dialogPressed();

    //widget panel slots
    void menuActionDialog( );
    
private:
    Ui::KitchenSink *ui;
    pageBuilder * m_objectPool;
    QLabel * m_dialogImg;
    bool m_threadsFinished;
    mutable QMutex m_mutex;

    void connectEvents( );

};

#endif // KITCHENSINK_H
