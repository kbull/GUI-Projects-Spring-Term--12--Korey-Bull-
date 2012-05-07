#ifndef KITCHENSINK_H
#define KITCHENSINK_H

#include <QMainWindow>

namespace Ui {
class KitchenSink;
}

class KitchenSink : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit KitchenSink(QWidget *parent = 0);
    ~KitchenSink();
    
private:
    Ui::KitchenSink *ui;

};

#endif // KITCHENSINK_H
