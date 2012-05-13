#define ROOT_QN         "KitchenSink"
#define SUGGEST_QN      "SuggestionList"
#define TABLABEL_QN     "TabLabels"
#define ARTIST_QN       "Artists"
#define SONGTYPE_QN     "SongTypes"
#define PAGE_QN         "PageText"
#define SONGSET_QN      "SongSet"


#include "filereader.h"
#include <QXmlStreamReader>
#include <QXmlStreamAttributes>
#include <QFile>



FileReader::FileReader(QObject *parent) :
    QObject(parent), m_xmlSrc("input_files/KitchenSinkData.xml")
{

}


FileReader::~FileReader( )
{

}


QString FileReader::getXmlSrc() const
{
    return m_xmlSrc;
}


bool FileReader::readFromXml()
{
    QMutexLocker lock(&m_mutex);
    QFile xmlFile(m_xmlSrc);
    QXmlStreamReader * reader = new QXmlStreamReader(&xmlFile);
    QXmlStreamAttributes tokenAttributes;
    QString tokenQn;
    bool success = false;

    if (QFile::exists(m_xmlSrc) && xmlFile.open(QIODevice::ReadOnly))
    {
        while (!reader->atEnd())
        {
            reader->readNext();

            if (reader->isStartElement() && reader->qualifiedName().toString() != tr(ROOT_QN))
            {
                tokenAttributes = reader->attributes();
                tokenQn = reader->qualifiedName().toString();

                if (!tokenQn.startsWith('S'))
                {
                    if (tokenQn == tr(TABLABEL_QN))
                        readTabLabels(tokenAttributes);

                    else if (tokenQn == tr(ARTIST_QN))
                        readArtistNames(tokenAttributes);

                    else if (tokenQn == tr(PAGE_QN))
                        readPageTexts(tokenAttributes);
                }
                else
                {
                    if (tokenQn == tr(SUGGEST_QN))
                        readSuggestionList(tokenAttributes);

                    else if (tokenQn == tr(SONGTYPE_QN))
                        readSongTypes(tokenAttributes);

                    else if (tokenQn == tr(SONGSET_QN))
                        readSongSet(reader, tokenAttributes);
                }
            }
        }

        success = true;
        xmlFile.close();
    }


    delete reader;
    reader = 0;

    return success;
}


void FileReader::readTabLabels(QXmlStreamAttributes token)
{
    QMutexLocker lock(&m_mutex);
    QString temp = "%1";
    QMap<Tabs, QString> tabLabels;

    for (int i = 0; i <= POPUP; ++i)
    {
        if (token.hasAttribute(temp.arg(i)))
            tabLabels[(Tabs)i] = token.value(temp.arg(i)).toString();
    }

    emit storeTabLabels(tabLabels);
}


void FileReader::readSuggestionList(QXmlStreamAttributes token)
{
    QMutexLocker lock(&m_mutex);
    QString temp = "%1";
    QStringList list;

    list.clear();

    if (token.hasAttribute(temp.arg(0)))
    {
        temp = token.value(temp.arg(0)).toString();

        list = temp.split(';');
    }

    emit storeSuggestionList(list);
}


void FileReader::readArtistNames(QXmlStreamAttributes token)
{
    QMutexLocker lock(&m_mutex);
    QString temp("%1");
    QMap<Artists, QString> names;

    for (int i = 0; i < ARTIST_MAX; ++i)
    {
        if (token.hasAttribute(temp.arg(i)))
            names[(Artists)i] = token.value(temp.arg(i)).toString();
    }

    emit storeArtistNames(names);
}


void FileReader::readSongTypes(QXmlStreamAttributes token)
{
    QMutexLocker lock(&m_mutex);
    QString temp("%1");
    QMap<SongType, QString> types;

    for (int i = 0; i < SONGTYPE_MAX; ++i)
    {
        if (token.hasAttribute(temp.arg(i)))
            types[(SongType)i] = token.value(temp.arg(i)).toString();
    }

    emit storeSongTypes(types);
}


void FileReader::readPageTexts(QXmlStreamAttributes token)
{
    QMutexLocker lock(&m_mutex);
    QString temp("%1");
    QMap<Tabs, QString> text;


    for (int i = 0; i <= POPUP; ++i)
    {
        if (token.hasAttribute(temp.arg(i)))
            text[(Tabs)i] = *(token.value(temp.arg(i)).string());
    }

    emit storePageTexts(text);
}


void FileReader::readSongSet(QXmlStreamReader * reader, QXmlStreamAttributes token)
{
    QMutexLocker lock(&m_mutex);
    QMap<Artists, QMap<SongType, QStringList>> songSet;
    QString tokenQn, temp = "%1";
    Artists art;

    if (reader)
    {
        for (qint8 i = 0, c = 0; i < ARTIST_MAX; ++i)
        {
            reader->readNext();

            if (reader->isStartElement())
            {
                token = reader->attributes();
                tokenQn = reader->qualifiedName().toString();

                if (tokenQn == "Beethoven")
                {
                    art = BEETHOVEN;
                    c = 4;
                }
                else if (tokenQn == "Brahms")
                {
                    art = BRAHMS;
                    c = 4;
                }
                else if (tokenQn == "Mozart")
                {
                    art = MOZART;
                    c = 1;
                }
                else
                {
                    c = 0;
                }

                for (qint8 k = 0; k < c; ++k)
                {
                    songSet[art][(SongType)k] = token.value(temp.arg(k)).string()->split(';');
                }
            }
        }
    }

    emit storeSongSet(songSet);
}


bool FileReader::readStyleSheets()
{
    bool success = false;
    QMap<Tabs, QString> styleSheets;
    QFile * file = 0;
    qint8 cnt = INTRO;
    QStringList fileList = QStringList()
                              << "introStyle.qss"
                              << "widgetStyle.qss"
                              << "panelStyle.qss"
                              << "listStyle.qss"
                              << "textStyle.qss"
                              << "popupStyle.qss";

   foreach (QString sheet, fileList)
   {
        if (QFile::exists(sheet))
        {
            file = new QFile(sheet);

            if (file->open(QIODevice::ReadOnly))
            {
                styleSheets[(Tabs)cnt] = file->readAll();
            }
            else
            {
                styleSheets[(Tabs)cnt] = "";
            }

            file->close();
            delete file;
            file = 0;
        }

        if (cnt < POPUP)
            ++cnt;
        else
            success = true;
   }

   emit storeStyleSheets(styleSheets);

   return success;
}
