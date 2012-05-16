#include "sinkmodel.h"
#include <QMutex>

static QMutex m_mutex;

// Ctor
SinkModel::SinkModel(QObject *parent) :
    QObject(parent), m_dialogBox(0),
    m_songSet(0), m_norm(0), m_pass(0), m_textE(0),
    m_cnorm(0), m_cpass(0), m_ctext(0)
{
    m_songSet = new QMap<SongType, QStringList> * [ARTIST_MAX];

    for (int i = 0; i < ARTIST_MAX; m_songSet[i++] = 0);
}

//Dtor
SinkModel::~SinkModel( )
{
    delete m_dialogBox;
    m_dialogBox = 0;


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


popDialog * SinkModel::getDialogBox()
{
    QMutexLocker lock(&m_mutex);

    if (!m_dialogBox)
        m_dialogBox = new popDialog;

    return m_dialogBox;
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


void SinkModel::setNormalCurs(QLabel * curs)
{
    m_cnorm = curs;
}


void SinkModel::setNormalEdit(QLineEdit * edit)
{
    m_norm = edit;
}


void SinkModel::setPassEdit(QLineEdit * edit)
{
    m_pass = edit;
}


void SinkModel::setTextEdit(QLineEdit * edit)
{
    m_textE = edit;
}


void SinkModel::setPassCurs(QLabel * curs)
{
    m_cpass = curs;
}


void SinkModel::setTextCurs(QLabel * curs)
{
    m_ctext = curs;
}


QLabel * SinkModel::getNormalCurs()
{
    return m_cnorm;
}


QLabel * SinkModel::getPassCurs()
{
    return m_cpass;
}


QLabel * SinkModel::getTextCurs()
{
    return m_ctext;
}


QLineEdit * SinkModel::getNormalEdit()
{
    return m_norm;
}


QLineEdit * SinkModel::getPassEdit()
{
    return m_pass;
}


QLineEdit * SinkModel::getTextEdit()
{
    return m_textE;
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
