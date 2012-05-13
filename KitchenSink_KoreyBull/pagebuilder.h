#ifndef PAGEBUILDER_H
#define PAGEBUILDER_H

#include <QObject>
#include <QMutex>
#include "tabbuilder.h"
#include "Enumerations.h"


class pageBuilder : public QObject
{
    Q_OBJECT
public:
    explicit pageBuilder(QObject * parent = 0);
    virtual ~pageBuilder();



signals:
    void objectCreationFinished();

public slots:
    void threadFinished();
    void spawnThreads( );


private:
    tabBuilder * m_pages[NUM_TABS];
    buildStrategy * m_builders[NUM_TABS];
    quint16 m_threadCount;
    mutable QMutex m_mutex;

};

#endif // PAGEBUILDER_H
