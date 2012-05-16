#ifndef FILEREADER_H
#define FILEREADER_H

#include <QObject>
#include <QStringList>
#include <QMutex>
#include <QMap>
#include "Enumerations.h"

// forward decl's
class QFile;


class FileReader : public QObject
{
    Q_OBJECT
public:
    explicit FileReader(QObject *parent = 0);
    virtual ~FileReader( );

    bool readFromCSV( );
    bool readFromHtml( );
    bool readStyleSheets( );


signals:
    void storeSuggestionList(QStringList);
    void storeStyleSheets(QMap<Tabs, QString>);
    void storeTabLabels(QMap<Tabs, QString>);
    void storeArtistNames(QMap<Artists, QString>);
    void storeSongTypes(QMap<SongType, QString>);
    void storePageTexts(QMap<Tabs, QString>);
    void storeSongSet(QMap<SongType, QStringList> *, Artists);


public slots:
    
private:
    mutable QMutex m_mutex;


};

#endif // FILEREADER_H
