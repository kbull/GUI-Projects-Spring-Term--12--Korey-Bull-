#ifndef FILEREADER_H
#define FILEREADER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QMutex>
#include <QMap>
#include "Enumerations.h"

// forward decl's
class QXmlStreamReader;
class QXmlStreamAttributes;


class FileReader : public QObject
{
    Q_OBJECT
public:
    explicit FileReader(QObject *parent = 0);
    virtual ~FileReader( );
    
    QString getXmlSrc( ) const;

    bool readFromXml( );
    bool readStyleSheets( );

signals:
    void storeSuggestionList(QStringList);
    void storeStyleSheets(QMap<Tabs, QString>);
    void storeTabLabels(QMap<Tabs, QString>);
    void storeArtistNames(QMap<Artists, QString>);
    void storeSongTypes(QMap<SongType, QString>);
    void storePageTexts(QMap<Tabs, QString>);
    void storeSongSet(QMap<Artists, QMap<SongType, QStringList>>);


public slots:
    
private:
    mutable QMutex m_mutex;
    const QString m_xmlSrc;

    void readSuggestionList(QXmlStreamAttributes);
    void readTabLabels(QXmlStreamAttributes);
    void readArtistNames(QXmlStreamAttributes);
    void readSongTypes(QXmlStreamAttributes);
    void readPageTexts(QXmlStreamAttributes);
    void readSongSet(QXmlStreamReader *, QXmlStreamAttributes);

};

#endif // FILEREADER_H
