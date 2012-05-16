#include "kitchensink.h"
#include "ui_kitchensink.h"
#include "filereader.h"
#include "pagefactory.h"
#include <QMessageBox>
#include <QScrollArea>



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


void KitchenSink::initKitchenSink( )
{
    m_reader = new FileReader;

    connect(m_reader, SIGNAL(storeArtistNames(QMap<Artists,QString>)), &(SinkModel::getInstance()), SLOT(initArtistNames(QMap<Artists,QString>)));
    connect(m_reader, SIGNAL(storePageTexts(QMap<Tabs,QString>)), &(SinkModel::getInstance()), SLOT(initPageTexts(QMap<Tabs,QString>)));
    connect(m_reader, SIGNAL(storeSongSet(QMap<SongType,QStringList>*,Artists)), &(SinkModel::getInstance()), SLOT(initSongSet(QMap<SongType,QStringList>*,Artists)));
    connect(m_reader, SIGNAL(storeSongTypes(QMap<SongType,QString>)), &(SinkModel::getInstance()), SLOT(initSongTypes(QMap<SongType,QString>)));
    connect(m_reader, SIGNAL(storeSuggestionList(QStringList)), &(SinkModel::getInstance()), SLOT(initSuggestionList(QStringList)));
    connect(m_reader, SIGNAL(storeTabLabels(QMap<Tabs,QString>)), &(SinkModel::getInstance()), SLOT(initTabLabels(QMap<Tabs,QString>)));
    connect(m_reader, SIGNAL(storeStyleSheets(QMap<Tabs,QString>)), &(SinkModel::getInstance()), SLOT(initStyleSheets(QMap<Tabs,QString>)));

    m_reader->ReadAll();

    delete m_reader;
    m_reader = 0;

    setUpMainWindow();
}


void KitchenSink::setUpMainWindow( )
{
    PageFactory * factory = new PageFactory;
    QTabWidget * tabWidget = ui->tabWidget;
    QMap<Tabs, QString> labels;
    const char * tabStrs[] = {
                                 "Intro",
                                 "Widgets",
                                 "Panels",
                                 "Lists",
                                 "Text",
                                 "Popups"
                               };

    tabWidget->clear();

    labels = SinkModel::getInstance().getTabLabels();

    tabWidget->insertTab(INTRO, factory->createIntroPage(this), labels[INTRO]);
    tabWidget->insertTab(WIDGET, factory->createWidgetPage(this), labels[WIDGET]);
    tabWidget->insertTab(PANEL, factory->createPanelPage(this), labels[PANEL]);
    tabWidget->insertTab(LIST, factory->createListPage(this), labels[LIST]);
    tabWidget->insertTab(TEXT, factory->createTextPage(this), labels[TEXT]);
    tabWidget->insertTab(POPUP, factory->createPopupPage(this), labels[POPUP]);

    delete factory;
    factory = 0;

    tabWidget->setCurrentIndex(INTRO);

    setStyleSheet("QTabWidget::tab-bar { left: 100px; }");
    connectEvents();
}

// public slots


// private

void KitchenSink::connectEvents( )
{

}


void KitchenSink::normCursorChg(int o, int n)
{
    if (o != n)
        cursorMoved(n, SinkModel::getInstance().getNormalCurs());
}


void KitchenSink::passCursorChg(int o, int n)
{
    if (o != n)
        cursorMoved(n, SinkModel::getInstance().getPassCurs());
}


void KitchenSink::textCursorChg(int o, int n)
{
    if (o != n)
        cursorMoved(n, SinkModel::getInstance().getTextCurs());
}


void KitchenSink::normSelectionChg()
{
    textSelection(SinkModel::getInstance().getNormalEdit(), SinkModel::getInstance().getNormalCurs());
}


void KitchenSink::passSelectionChg()
{
    textSelection(SinkModel::getInstance().getPassEdit(), SinkModel::getInstance().getPassCurs());
}


void KitchenSink::textSelectionChg()
{
    textSelection(SinkModel::getInstance().getTextEdit(), SinkModel::getInstance().getTextCurs());
}

void KitchenSink::menuActionBox()
{
    QMessageBox box;

    box.setWindowTitle("The page at gwt.google.com says:");
    box.setText("Thank you for selecting a menu item.");

    box.setStandardButtons(QMessageBox::Ok);

    box.exec();
}


void KitchenSink::dialogRequested()
{
    SinkModel::getInstance().getDialogBox()->exec();
}


void KitchenSink::popupRequested()
{
    QMessageBox box;

    box.setText("Click anywhere outside this popup to make it disappear.");
    box.setWindowModality(Qt::WindowModal);
    box.setStandardButtons(QMessageBox::NoButton);
    box.setWindowFlags(Qt::Popup | Qt::Widget);
    box.setAttribute(Qt::WA_ShowWithoutActivating);
    box.setBaseSize(128, 48);

    box.exec();
}


void KitchenSink::cursorMoved(int n, QLabel * label)
{
    if (label)
    {
        QString temp(" %1, 0");

        label->setText("Selection:" + temp.arg(n));
    }
}


void KitchenSink::textSelection(QLineEdit * edit, QLabel * label)
{
    if (edit && label)
    {
        QString temp(" %1");
        int pos = edit->selectionStart();

        if (edit->hasSelectedText())
            label->setText("Selection:" + temp.arg(pos) + "," + temp.arg(pos + edit->selectedText().size()));
        else
            cursorMoved(edit->cursorPosition(), label);
    }
}
