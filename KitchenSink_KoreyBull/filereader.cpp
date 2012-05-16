#include "filereader.h"
#include <QFile>


#define FILE_LINES 13
#define SUG_LIST 0
#define TAB 1
#define ART 2
#define TYPE 3
#define BC 4
#define BQ 5
#define BS 6
#define BSY 7
#define BAC 8
#define BAQ 9
#define BAS 10
#define BAY 11
#define MC 12


FileReader::FileReader(QObject *parent) :
    QObject(parent)
{

}


FileReader::~FileReader( )
{

}


bool FileReader::readFromCSV()
{
    QMutexLocker lock(&m_mutex);
    QFile * fin = new QFile("input_files/inputStrs.txt");
    QMap<SongType, QStringList> * songSet = 0;
    QMap<Tabs, QString> * tabText = 0;
    QMap<SongType, QString> * types = 0;
    QMap<Artists, QString> * artists = 0;
    QStringList list;
    QString temp;
    qint64 lineLength = 0;
    char buf[700] = {0};
    bool success = false;


    if (fin->open(QIODevice::ReadOnly))
    {
        for (int i = 0; i < FILE_LINES; ++i)
        {
            lineLength = fin->readLine(buf, sizeof(buf));

            if (lineLength != -1)
            {
                switch (i)
                {
                case SUG_LIST:
                    temp = buf;
                    list = temp.split(";");

                    emit storeSuggestionList(list);
                    list.clear();
                    temp.clear();
                    break;

                case TAB:
                    tabText = new QMap<Tabs, QString>;
                    temp = buf;
                    list = temp.split(";");

                    for (int i = 0; i <= POPUP; ++i)
                    {
                        tabText->insert((Tabs)i, list.at(i));
                    }

                    emit storeTabLabels(*tabText);
                    delete tabText;
                    temp.clear();
                    list.clear();
                    tabText = 0;
                    break;

                case ART:
                    artists = new QMap<Artists, QString>;
                    temp = buf;
                    list = temp.split(";");

                    for (int i = 0; i < ARTIST_MAX; ++i)
                    {
                        artists->insert((Artists)i, list.at(i));
                    }

                    emit storeArtistNames(*artists);
                    delete artists;
                    artists = 0;
                    temp.clear();
                    list.clear();
                    break;

                case TYPE:
                    types = new QMap<SongType, QString>;
                    temp = buf;
                    list = temp.split(";");

                    for (int i = 0; i < SONGTYPE_MAX; ++i)
                    {
                        types->insert((SongType)i, list.at(i));
                    }

                    emit storeSongTypes(*types);
                    delete types;
                    types = 0;
                    temp.clear();
                    list.clear();
                    break;

                case BC:
                    songSet = new QMap<SongType, QStringList>;
                    temp = buf;
                    songSet->insert(CONCERTOS, temp.split(";"));

                    break;

                case BQ:
                    temp = buf;
                    songSet->insert(QUARTETS, temp.split(";"));

                    break;

                case BS:
                    temp = buf;
                    songSet->insert(SONATAS, temp.split(";"));

                    break;

                case BSY:
                    temp = buf;
                    songSet->insert(SYMPHONIES, temp.split(";"));

                    emit storeSongSet(songSet, BEETHOVEN);

                    break;

                case BAC:
                    songSet = new QMap<SongType, QStringList>;
                    temp = buf;
                    songSet->insert(CONCERTOS, temp.split(";"));

                    break;

                case BAQ:
                    temp = buf;
                    songSet->insert(QUARTETS, temp.split(";"));

                    break;

                case BAS:
                    temp = buf;
                    songSet->insert(SONATAS, temp.split(";"));

                    break;

                case BAY:
                    temp = buf;
                    songSet->insert(SYMPHONIES, temp.split(";"));

                    emit storeSongSet(songSet, BRAHMS);
                    break;

                case MC:
                    songSet = new QMap<SongType, QStringList>;
                    temp = buf;
                    songSet->insert(CONCERTOS, temp.split(";"));

                    emit storeSongSet(songSet, MOZART);
                    success = true;

                    break;

                default:
                    i = FILE_LINES;
                }
            }
        }

        fin->close();
    }

    delete fin;

    return success;
}


bool FileReader::readFromHtml( )
{
    QMutexLocker lock(&m_mutex);
    QMap<Tabs, QString> text;
    QFile * file = 0;
    qint8 ct = 0;
    QStringList files = QStringList() << "html/intro.html"
                                      << "html/widget.html"
                                      << "html/panel.html"
                                      << "html/list.html"
                                      << "html/text.html"
                                      << "html/popup.html";

    for (qint8 i = INTRO; i <= POPUP; ++i)
    {
        file = new QFile(files.at(i));

        if (file->open(QIODevice::ReadOnly))
        {
            ++ct;
            text[(Tabs)i] = file->readAll();
            file->close();
        }

        delete file;
        file = 0;
    }

    emit storePageTexts(text);

    return (ct == POPUP);
}


bool FileReader::readStyleSheets()
{
    QMutexLocker lock(&m_mutex);
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
