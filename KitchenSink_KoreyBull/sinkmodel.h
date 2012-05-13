#ifndef SINKMODEL_H
#define SINKMODEL_H

#include <QObject>
#include <QMap>
#include <QStringList>
#include <QMessageBox>
#include "Enumerations.h"
#include "popdialog.h"
#include "intropage.h"
#include "panelpage.h"
#include "widgetpage.h"
#include "popuppage.h"
#include "textpage.h"
#include "listpage.h"


// Singleton Model
class SinkModel : public QObject
{
    Q_OBJECT
public:
    virtual ~SinkModel( );

    //Multiton stuff
    static SinkModel & getInstance( );

    // factory method
    tabPage * createTabPage(Tabs key);

    // getters
    const popDialog * getDialogBox( );
    const QMessageBox * getMenuMsgBox( );

    QStringList getSuggestionList( );

    QString getStyleSheet(Tabs key);
    QMap<Tabs, QString> getStyleSheets( );

    QString getTabLabel(Tabs key);
    QMap<Tabs, QString> getTabLabels();

    QString getArtistName(Artists key);
    QMap<Artists, QString> getArtists();

    QString getSongType(SongType key);
    QMap<SongType, QString> getSongTypes();

    QString getPageText(Tabs key);
    QMap<Tabs, QString> getPageTexts();

    QStringList getSongs(Artists artist, SongType type);
    QMap<Artists, QMap<SongType, QStringList>> getSongSet( );

signals:

public slots:
    void initSuggestionList(QStringList);
    void initStyleSheets(QMap<Tabs, QString>);
    void initTabLabels(QMap<Tabs, QString>);
    void initArtistNames(QMap<Artists, QString>);
    void initSongTypes(QMap<SongType, QString>);
    void initPageTexts(QMap<Tabs, QString>);
    void initSongSet(QMap<Artists, QMap<SongType, QStringList>>);


private:
    explicit SinkModel(QObject *parent = 0);
    SinkModel(const SinkModel &); // removing copy ctor capabilities
    SinkModel & operator=(const SinkModel &); // removing assignment op. capabilities

    // soon to come popup dialog widget
    popDialog * m_dialogBox;
    QMessageBox * m_mesgBox;
    
    //storage members
    QStringList m_suggestions;
    QMap<Tabs, QString> m_styles;
    QMap<Tabs, QString> m_tabLabels;
    QMap<Artists, QString> m_artists;
    QMap<SongType, QString> m_songTypes;
    QMap<Tabs, QString> m_pageText;
    QMap<Artists, QMap<SongType, QStringList>> m_songSet;

};

#endif // SINKMODEL_H
