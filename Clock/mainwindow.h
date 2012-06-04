#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QThread>
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
    void closeEvent(QCloseEvent *);

protected:
    
private:
    Ui::MainWindow * _ui;
    ClockController * _ctrl;
    QThread * _ctrlThread;
    QHash<ViewMode, ClockView *> _views;

    void purgeViews();
    void initViews();
    void initController();
    void enableButtons(bool enable);

    MainWindow(const MainWindow &);
    MainWindow & operator=(const MainWindow &);

};

#endif // MAINWINDOW_H
