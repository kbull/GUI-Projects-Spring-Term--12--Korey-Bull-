/******************************************************************************
* Author : Korey Bull
* Date Created : 5/6/2012
* Project Title : Lab 1 - Google Kitchen Sink w/ Qt
* Course/Term : CST 238 / Spring 2012
*
* Summary :
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
******************************************************************************/
#include <QtGui/QApplication>
//#include "kitchensink.h"
#include "sinkmodel.h"
#include "filereader.h"
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    KitchenSink w;

//    w.startObjectCreation();

//    w.setUpMainWindow();

//    w.show();
    FileReader * reader = new FileReader;

    QApplication::connect(reader, SIGNAL(storeArtistNames(QMap<Artists,QString>)), &(SinkModel::getInstance()), SLOT(initArtistNames(QMap<Artists,QString>)));
    QApplication::connect(reader, SIGNAL(storePageTexts(QMap<Tabs,QString>)), &(SinkModel::getInstance()), SLOT(initPageTexts(QMap<Tabs,QString>)));
    QApplication::connect(reader, SIGNAL(storeSongTypes(QMap<SongType,QString>)), &(SinkModel::getInstance()), SLOT(initSongTypes(QMap<SongType,QString>)));
    QApplication::connect(reader, SIGNAL(storeStyleSheets(QMap<Tabs,QString>)), &(SinkModel::getInstance()), SLOT(initStyleSheets(QMap<Tabs,QString>)));
    QApplication::connect(reader, SIGNAL(storeSuggestionList(QStringList)), &(SinkModel::getInstance()), SLOT(initSuggestionList(QStringList)));
    QApplication::connect(reader, SIGNAL(storeTabLabels(QMap<Tabs,QString>)), &(SinkModel::getInstance()), SLOT(initTabLabels(QMap<Tabs,QString>)));


    reader->readFromXml();


    QMap<Artists, QString> artists = (SinkModel::getInstance()).getArtists();
    QMap<Tabs, QString> texts = (SinkModel::getInstance()).getPageTexts();
    QMap<SongType, QString> types = (SinkModel::getInstance()).getSongTypes();
    QMap<Tabs, QString> labels = (SinkModel::getInstance()).getTabLabels();
    QStringList suggestions = (SinkModel::getInstance()).getSuggestionList();

    QFile * file = new QFile(":/dbg_stub_output.txt");

    if (file->open(QIODevice::WriteOnly))
    {
        file->resize(0);

        QString fileData;
        QString temp("%1");

        fileData = "Key-Value pairs\n\n";

        fileData += ("Artists: " + temp.arg(artists.count()));

        foreach (Artists key, artists.keys())
        {
            fileData += ("Key: " + temp.arg(key) + " Value: " + artists[key]);
            fileData += "\n";
        }

        file->write(fileData.toAscii());
        fileData.clear();

        fileData += ("TextPages: " + temp.arg(texts.count()));

        foreach (Tabs key, texts.keys())
        {
            fileData += ("Key: " + temp.arg(key) + " Value: " + texts[key]);
            fileData += "\n";
        }

        file->write(fileData.toAscii());
        fileData.clear();

        fileData += ("Song Types: " + temp.arg(types.count()));

        foreach (SongType key, types.keys())
        {
            fileData += ("Key: " + temp.arg(key) + " Value: " + types[key]);
            fileData += "\n";
        }

        file->write(fileData.toAscii());
        fileData.clear();

        fileData += ("Tab Labels: " + temp.arg(labels.count()));

        foreach (Tabs key, labels.keys())
        {
            fileData += ("Key: " + temp.arg(key) + " Value: " + labels[key]);
            fileData += "\n";
        }

        file->write(fileData.toAscii());
        fileData.clear();

        fileData += "\n\n\t**** SUGGESTION LIST ****\n\n";
        fileData += ("Count of List items: " + temp.arg(suggestions.count()));

        foreach (QString str, suggestions)
        {
            fileData += (str + "\n");
        }

        file->write(fileData.toAscii());

        file->close();

        delete file;
        file = 0;

    }
    
    return a.exec();
}
