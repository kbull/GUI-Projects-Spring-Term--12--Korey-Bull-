#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVector>
#include <QThread>
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

    void initAndSetup();

signals:

public slots:
    void switchViewPrev();
    void switchViewNext();

protected:
    
private:
    Ui::MainWindow * _ui;
    QPushButton * _viewNx;
    QPushButton * _viewPr;
    ClockModel * _model;
    QThread * _modelThread;
    QVector<ClockView *> _views;

    void purgeViews();
    void initViews();
    void initModel();
    void collectThreads();

};

#endif // MAINWINDOW_H
