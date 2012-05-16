#ifndef SINKMODEL_H
#define SINKMODEL_H

#include <QObject>
#include <QMap>
#include <QVector>
#include <QStringList>
#include <QMessageBox>
#include <QLineEdit>
#include "Enumerations.h"
#include "popdialog.h"


// Singleton Model
class SinkModel : public QObject
{
    Q_OBJECT
public:
    virtual ~SinkModel( );

    //Multiton stuff
    static SinkModel & getInstance( );

    // getters
    popDialog * getDialogBox( );

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
    QMap<SongType, QStringList> getArtistWorks(Artists artist);

    void setNormalEdit(QLineEdit *);
    void setPassEdit(QLineEdit *);
    void setTextEdit(QLineEdit *);

    QLineEdit * getNormalEdit();
    QLineEdit * getPassEdit();
    QLineEdit * getTextEdit();


    void setNormalCurs(QLabel *);
    void setPassCurs(QLabel *);
    void setTextCurs(QLabel *);

    QLabel * getNormalCurs();
    QLabel * getPassCurs();
    QLabel * getTextCurs();


signals:

public slots:
    void initSuggestionList(QStringList);
    void initStyleSheets(QMap<Tabs, QString>);
    void initTabLabels(QMap<Tabs, QString>);
    void initArtistNames(QMap<Artists, QString>);
    void initSongTypes(QMap<SongType, QString>);
    void initPageTexts(QMap<Tabs, QString>);
    void initSongSet(QMap<SongType, QStringList> *, Artists key);


private:
    explicit SinkModel(QObject *parent = 0);
    SinkModel(const SinkModel &); // removing copy ctor capabilities
    SinkModel & operator=(const SinkModel &); // removing assignment op. capabilities

    // soon to come popup dialog widget
    popDialog * m_dialogBox;
    QLineEdit * m_norm;
    QLineEdit * m_pass;
    QLineEdit * m_textE;
    QLabel * m_cnorm;
    QLabel * m_cpass;
    QLabel * m_ctext;
    
    //storage members
    QStringList m_suggestions;
    QMap<Tabs, QString> m_styles;
    QMap<Tabs, QString> m_tabLabels;
    QMap<Artists, QString> m_artists;
    QMap<SongType, QString> m_songTypes;
    QMap<Tabs, QString> m_pageText;
    QMap<SongType,QStringList> ** m_songSet;

};

#endif // SINKMODEL_H
