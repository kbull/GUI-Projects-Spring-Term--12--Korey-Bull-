#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHash>
#include <QThread>
#include <QMutex>
#include "clockview.h"
#include "clockcontroller.h"


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
    void clockViewChanged(bool dir);

public slots:
    void switchViewPrev();
    void switchViewNext();

protected:
    
private:
    Ui::MainWindow * _ui;
    QPushButton * _viewNx;
    QPushButton * _viewPr;
    ClockController * _ctrl;
    QThread * _ctrlThread;
    QHash<ViewMode, ClockView *> _views;
    mutable QMutex _mutex;

    void purgeViews();
    void initViews();
    void initController();
    void collectThreads();

    MainWindow(const MainWindow &);
    MainWindow & operator=(const MainWindow &);

};

#endif // MAINWINDOW_H
