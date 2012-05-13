#ifndef POPDIALOG_H
#define POPDIALOG_H

#include <QDialog>

namespace Ui {
class popDialog;
}

class popDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit popDialog(QWidget *parent = 0);
    virtual ~popDialog();
    
private:
    Ui::popDialog *ui;
};

#endif // POPDIALOG_H
