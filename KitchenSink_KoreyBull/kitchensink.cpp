#include "kitchensink.h"
#include "ui_kitchensink.h"
#include "filereader.h"
#include <QMessageBox>
#include <QScrollArea>
#include <QThread>


KitchenSink::KitchenSink(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::KitchenSink), m_reader(0)
{
    ui->setupUi(this);

}

KitchenSink::~KitchenSink()
{
    delete ui;
    ui = 0;
}


void KitchenSink::startObjectCreation( )
{
    QThread * fileThread = new QThread;
    m_reader = new FileReader;

    m_reader->moveToThread(fileThread);

    connect(fileThread, SIGNAL(started()), m_reader, SLOT(ReadAll()));
    connect(m_reader, SIGNAL(finished()), fileThread, SLOT(quit()));
    connect(fileThread, SIGNAL(finished()), fileThread, SLOT(deleteLater()));
    connect(fileThread, SIGNAL(finished()), this, SLOT(objectCreationFinished()));
    connect(m_reader, SIGNAL(storeArtistNames(QMap<Artists,QString>)), &(SinkModel::getInstance()), SLOT(initArtistNames(QMap<Artists,QString>)));
    connect(m_reader, SIGNAL(storePageTexts(QMap<Tabs,QString>)), &(SinkModel::getInstance()), SLOT(initPageTexts(QMap<Tabs,QString>)));
    connect(m_reader, SIGNAL(storeSongSet(QMap<SongType,QStringList>*,Artists)), &(SinkModel::getInstance()), SLOT(initSongSet(QMap<SongType,QStringList>*,Artists)));
    connect(m_reader, SIGNAL(storeSongTypes(QMap<SongType,QString>)), &(SinkModel::getInstance()), SLOT(initSongTypes(QMap<SongType,QString>)));
    connect(m_reader, SIGNAL(storeSuggestionList(QStringList)), &(SinkModel::getInstance()), SLOT(initSuggestionList(QStringList)));
    connect(m_reader, SIGNAL(storeTabLabels(QMap<Tabs,QString>)), &(SinkModel::getInstance()), SLOT(initTabLabels(QMap<Tabs,QString>)));
    connect(m_reader, SIGNAL(storeStyleSheets(QMap<Tabs,QString>)), &(SinkModel::getInstance()), SLOT(initStyleSheets(QMap<Tabs,QString>)));

    fileThread->start();
    fileThread->wait();
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

//    tabWidget->clear();

//    for (int i = INTRO; i <= POPUP; ++i)
//    {
//        tabWidget->insertTab(i, Multiton::getInstance().getPage((Tabs)i),
//                             tabStrs[i]);
//    }

//    tabWidget->setCurrentIndex(INTRO);

    setStyleSheet("QTabWidget::tab-bar { left: 100px; }");
    connectEvents();
}

// public slots

void KitchenSink::objectCreationFinished( )
{
    QMutexLocker lock(&m_mutex);

    delete m_reader;
    m_reader = 0;

    setUpMainWindow();
}


// private

void KitchenSink::connectEvents( )
{

}


void KitchenSink::popupPressed( )
{

}


void KitchenSink::dialogPressed( )
{
}


void KitchenSink::menuActionDialog( )
{
    QMessageBox box;

    box.setWindowTitle("The page at gwt.google.com says:");
    box.setText("Thank you for selecting a menu item.");

    box.setStandardButtons(QMessageBox::Ok);

    box.exec();
}
