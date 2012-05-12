#include "kitchensink.h"
#include "ui_kitchensink.h"
#include "multiton.h"
#include <QMessageBox>
#include <QScrollArea>


KitchenSink::KitchenSink(QWidget *parent) :
    QMainWindow(parent), m_threadsFinished(false),
    ui(new Ui::KitchenSink), m_objectPool(new pageBuilder),
    m_dialogImg(0)
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
    QMessageBox dialog;
    QVBoxLayout form;
    QLabel * text = new QLabel("This is an example of a standard dialog box component");
    QPushButton * close = new QPushButton("Close");
    QScrollArea * scroll = new QScrollArea;

    dialog.setModal(true);
    dialog.setWindowTitle("Sample DialogBox");

    m_dialogImg = new QLabel;
    m_dialogImg->setBackgroundRole(QPalette::Base);
    m_dialogImg->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    m_dialogImg->setScaledContents(true);

    QImage image("jimmy.jpg", "JPG");

    m_dialogImg->setPixmap(QPixmap::fromImage(image));
    m_dialogImg->resize(image.width(), image.height());
    m_dialogImg->setBaseSize(image.width(), image.height());

    scroll->setBackgroundRole(QPalette::Dark);
    scroll->setWidget(m_dialogImg);
    scroll->setBaseSize(m_dialogImg->width(), m_dialogImg->height());

    form.addWidget(text, 0, Qt::AlignHCenter);
    form.addWidget(scroll, 0, Qt::AlignCenter);
    form.addWidget(close, 0, Qt::AlignRight);

    delete dialog.layout();
    dialog.setLayout(&form);

    connect(close, SIGNAL(clicked()), &dialog, SLOT(accept()));


    dialog.show();
    int ret = dialog.exec();

    delete close;
    delete scroll;
    delete text;
}


void KitchenSink::menuActionDialog( )
{
    QMessageBox box;

    box.setWindowTitle("The page at gwt.google.com says:");
    box.setText("Thank you for selecting a menu item.");

    box.setStandardButtons(QMessageBox::Ok);

    box.exec();
}
