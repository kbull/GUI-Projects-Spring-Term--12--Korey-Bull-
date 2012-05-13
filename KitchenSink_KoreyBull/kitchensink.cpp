#include "kitchensink.h"
#include "ui_kitchensink.h"
#include "multiton.h"
#include <QMessageBox>
#include <QScrollArea>


KitchenSink::KitchenSink(QWidget *parent) :
    QMainWindow(parent), m_threadsFinished(false),
    ui(new Ui::KitchenSink), m_objectPool(new pageBuilder),
    m_dialogBox(0)
{
    ui->setupUi(this);

}

KitchenSink::~KitchenSink()
{
    delete ui;
    ui = 0;

    delete m_objectPool;
    m_objectPool = 0;

    delete m_dialogBox;
    m_dialogBox = 0;
}


void KitchenSink::startObjectCreation( )
{
//    QThread * thread = new QThread;

//    m_objectPool->moveToThread(thread);

    connect(m_objectPool, SIGNAL(objectCreationFinished()),
            this, SLOT(objectCreationFinished()));
//    connect(thread, SIGNAL(started()), m_objectPool, SLOT(spawnThreads()));
//    connect(thread, SIGNAL(finished()), this, SLOT(objectCreationFinished()));
//    connect(m_objectPool, SIGNAL(objectCreationFinished()), thread, SLOT(deleteLater()));

//    thread->start();

    m_objectPool->spawnThreads();
}


void KitchenSink::setUpMainWindow( )
{
    QTabWidget * tabWidget = ui->tabWidget;
    const char * tabStrs[] = {
                                 "Intro",
                                 "Widgets",
                                 "Panels",
                                 "Lists",
                                 "Text",
                                 "Popups"
                               };

    tabWidget->clear();

    for (int i = INTRO; i <= POPUP; ++i)
    {
        tabWidget->insertTab(i, Multiton::getInstance().getPage((Tabs)i),
                             tabStrs[i]);
    }

    tabWidget->setCurrentIndex(INTRO);

    setStyleSheet("QTabWidget::tab-bar { left: 100px; }");
    connectEvents();
}


bool KitchenSink::areThreadsFinished( ) const
{
    return m_threadsFinished;
}

// public slots

void KitchenSink::objectCreationFinished( )
{
    QMutexLocker lock(&m_mutex);

    m_threadsFinished = true;
}


// private

void KitchenSink::connectEvents( )
{

    popupPage * temp = dynamic_cast<popupPage *>(Multiton::getInstance().getPage(POPUP));

    connect(temp, SIGNAL(popup()), this, SLOT(popupPressed()));
    connect(temp, SIGNAL(dialog()), this, SLOT(dialogPressed()));

    widgetPage * temp0 = dynamic_cast<widgetPage *>(Multiton::getInstance().getPage(WIDGET));

    connect(temp0, SIGNAL(menuDialog()), this, SLOT(menuActionDialog()));
}


void KitchenSink::popupPressed( )
{

}


void KitchenSink::dialogPressed( )
{
    if (m_dialogBox == 0)
        m_dialogBox = new popDialog;

    m_dialogBox->setWindowTitle("Standard DialogBox");
    m_dialogBox->setEnabled(true);
    m_dialogBox->show();
    m_dialogBox->exec();
    m_dialogBox->hide();
    m_dialogBox->setEnabled(false);
}


void KitchenSink::menuActionDialog( )
{
    QMessageBox box;

    box.setWindowTitle("The page at gwt.google.com says:");
    box.setText("Thank you for selecting a menu item.");

    box.setStandardButtons(QMessageBox::Ok);

    box.exec();
}
