#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHash>
#include "clockview.h"
#include "clockmodel.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QPushButton * _viewForward;
    QPushButton * _viewBackward;
    ClockModel * _model;
    QHash<ViewMode, ClockView *> _views;


};

#endif // MAINWINDOW_H
