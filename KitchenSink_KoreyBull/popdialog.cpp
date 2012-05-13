#include "popdialog.h"
#include "ui_popdialog.h"

popDialog::popDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popDialog)
{
    ui->setupUi(this);
}

popDialog::~popDialog()
{
    delete ui;
    ui = 0;
}
