#ifndef BUILDSTRATEGY_H
#define BUILDSTRATEGY_H

class tabPage;

class buildStrategy
{
public:    
    virtual ~buildStrategy();

    virtual void buildPage() = 0;

protected:
    buildStrategy(tabPage *);

    tabPage * m_page;

private:
    buildStrategy(const buildStrategy &);
    buildStrategy & operator=(const buildStrategy &);

};

#endif // BUILDSTRATEGY_H
