#ifndef TABBUILDER_H
#define TABBUILDER_H

#include <QThread>
#include <QMutex>
#include "buildstrategy.h"


class tabBuilder : public QThread
{
    Q_OBJECT
public:
    explicit tabBuilder(QObject *parent = 0);

    void setBuildStrategy(buildStrategy * builder);
    const buildStrategy * getBuildStrategy( ) const;
    
signals:

public slots:
    void start();

private:
    buildStrategy * m_builder;
    QMutex m_mutex;
    
protected:
    void run( );
};

#endif // TABBUILDER_H
