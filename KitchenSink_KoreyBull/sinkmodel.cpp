#include "sinkmodel.h"
#include <QMutex>

static QMutex m_mutex;

// Ctor
SinkModel::SinkModel(QObject *parent) :
    QObject(parent), m_dialogBox(0), m_mesgBox(0),
    m_songSet(0)
{
    m_songSet = new QMap<SongType, QStringList> * [ARTIST_MAX];

    for (int i = 0; i < ARTIST_MAX; m_songSet[i++] = 0);
}

//Dtor
SinkModel::~SinkModel( )
{
    delete m_dialogBox;
    m_dialogBox = 0;

    delete m_mesgBox;
    m_mesgBox = 0;

    for (int i = 0; i < ARTIST_MAX; ++i)
    {
        delete m_songSet[i];
        m_songSet[i] = 0;
    }

    delete [] m_songSet;
    m_songSet = 0;
}

//Accessors
SinkModel & SinkModel::getInstance( )
{
    QMutexLocker lock(&m_mutex);

    static SinkModel instance;

    return instance;
}


tabPage * SinkModel::createTabPage(Tabs key)
{
    QMutexLocker lock(&m_mutex);

    tabPage * temp = 0;

    switch(key)
    {
    case INTRO:
        temp = new introPage;
        temp->initializePage();
        break;

    case WIDGET:
        temp = new widgetPage;
        temp->initializePage();
        break;

    case PANEL:
        temp = new panelPage;
        temp->initializePage();
        break;

    case LIST:
        temp = new listPage;
        temp->initializePage();
        break;

    case TEXT:
        temp = new textPage;
        temp->initializePage();
        break;

    case POPUP:
        temp = new popupPage;
        temp->initializePage();
        break;

    default:
        temp = 0;
    }

    return temp;
}


const popDialog * SinkModel::getDialogBox()
{
    QMutexLocker lock(&m_mutex);

    return m_dialogBox;
}


const QMessageBox * SinkModel::getMenuMsgBox()
{
    QMutexLocker lock(&m_mutex);

    return m_mesgBox;
}


QStringList SinkModel::getSuggestionList()
{
    QMutexLocker lock(&m_mutex);

    return m_suggestions;
}


QString SinkModel::getStyleSheet(Tabs key)
{
    QMutexLocker lock(&m_mutex);

    if (!m_styles.contains(key))
        return QString();

    return m_styles[key];
}


QMap<Tabs, QString> SinkModel::getStyleSheets()
{
    QMutexLocker lock(&m_mutex);

    return m_styles;
}


QString SinkModel::getTabLabel(Tabs key)
{
    QMutexLocker lock(&m_mutex);

    if (!m_tabLabels.contains(key))
        return QString();

    return m_tabLabels[key];
}


QMap<Tabs, QString> SinkModel::getTabLabels()
{
    QMutexLocker lock(&m_mutex);

    return m_tabLabels;
}


QString SinkModel::getArtistName(Artists key)
{
    QMutexLocker lock(&m_mutex);

    if (!m_artists.contains(key))
        return QString();

    return m_artists[key];
}


QMap<Artists, QString> SinkModel::getArtists( )
{
    QMutexLocker lock(&m_mutex);

    return m_artists;
}


QString SinkModel::getSongType(SongType key)
{
    QMutexLocker lock(&m_mutex);

    if (!m_songTypes.contains(key))
        return QString();

    return m_songTypes[key];
}


QMap<SongType, QString> SinkModel::getSongTypes()
{
    QMutexLocker lock(&m_mutex);

    return m_songTypes;
}


QString SinkModel::getPageText(Tabs key)
{
    QMutexLocker lock(&m_mutex);

    if (!m_pageText.contains(key))
        return QString();

    return m_pageText[key];
}


QMap<Tabs, QString> SinkModel::getPageTexts()
{
    QMutexLocker lock(&m_mutex);

    return m_pageText;
}


QStringList SinkModel::getSongs(Artists artist, SongType type)
{
    QMutexLocker lock(&m_mutex);
    QStringList temp;

    if ((artist >= BEETHOVEN) && (artist < ARTIST_MAX) && m_songSet)
    {
        if (m_songSet[artist] && m_songSet[artist]->contains(type))
            temp = (*(m_songSet[artist]))[type];
    }


    return temp;
}


QMap<SongType, QStringList> SinkModel::getArtistWorks(Artists artist)
{
    QMutexLocker lock(&m_mutex);
    QMap<SongType, QStringList> temp;

    if ((artist >= BEETHOVEN) && (artist < ARTIST_MAX))
    {
        temp = *(m_songSet[artist]);
    }

    return temp;
}


// public slots

void SinkModel::initSuggestionList(QStringList strs)
{
    m_suggestions = strs;
}


void SinkModel::initStyleSheets(QMap<Tabs, QString> sheets)
{
    m_styles = sheets;
}


void SinkModel::initTabLabels(QMap<Tabs, QString> labels)
{
    m_tabLabels = labels;
}


void SinkModel::initArtistNames(QMap<Artists, QString> artists)
{
    m_artists = artists;
}


void SinkModel::initSongTypes(QMap<SongType, QString> types)
{
    m_songTypes = types;
}


void SinkModel::initPageTexts(QMap<Tabs, QString> pages)
{
    m_pageText = pages;
}


void SinkModel::initSongSet(QMap<SongType, QStringList> * songSet, Artists key)
{
    if (songSet && m_songSet && key >= BEETHOVEN && key < ARTIST_MAX)
    {
        m_songSet[key] = songSet;
    }
}
