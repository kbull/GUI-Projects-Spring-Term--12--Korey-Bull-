#include "tabbuilder.h"


tabBuilder::tabBuilder(QObject *parent) :
    QThread(parent), m_builder(0)
{
    moveToThread(this);
}


void tabBuilder::start( )
{
    run();

    emit QThread::finished();
}


void tabBuilder::run( )
{
    m_mutex.lock();

    if (m_builder != 0)
        m_builder->buildPage();

    m_mutex.unlock();
}


void tabBuilder::setBuildStrategy(buildStrategy *builder)
{
    if (m_builder == 0)
        m_builder = builder;
    else
    {
        delete m_builder;
        m_builder = builder;
    }
}


const buildStrategy * tabBuilder::getBuildStrategy( ) const
{
    return m_builder;
}
