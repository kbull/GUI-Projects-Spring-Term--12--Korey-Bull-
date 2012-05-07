#include "kitchensink.h"
#include "ui_kitchensink.h"

KitchenSink::KitchenSink(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KitchenSink)
{
    ui->setupUi(this);
}

KitchenSink::~KitchenSink()
{
    delete ui;
}
