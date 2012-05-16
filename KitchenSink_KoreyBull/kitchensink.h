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

    void initKitchenSink( );


signals:

public slots:
    void normCursorChg(int, int);
    void passCursorChg(int, int);
    void textCursorChg(int, int);

    //edit selection change
    void normSelectionChg();
    void passSelectionChg();
    void textSelectionChg();

    void menuActionBox();
    void dialogRequested();
    void popupRequested();
    
private:
    Ui::KitchenSink *ui;
    FileReader * m_reader;
    mutable QMutex m_mutex;

    void connectEvents( );
    void setUpMainWindow( );
    void cursorMoved(int n, QLabel *);
    void textSelection(QLineEdit *, QLabel *);

};

#endif // KITCHENSINK_H
