#ifndef ENUMERATIONS_H
#define ENUMERATIONS_H


enum Tabs
{
    INTRO = 0,
    WIDGET = 1,
    PANEL = 2,
    LIST = 3,
    TEXT = 4,
    POPUP = 5
};

#define NUM_TABS 6

enum Spacers
{
    LEFT_SP = 0,
    TOP_SP = 1,
    RIGHT_SP = 2,
    BOT_SP = 3
};

enum Artists
{
    BEETHOVEN = 0,
    BRAHMS = 1,
    MOZART = 2,
    ARTIST_MAX = 3
};

enum SongType
{
    CONCERTOS = 0,
    QUARTETS = 1,
    SONATAS = 2,
    SYMPHONIES = 3,
    SONGTYPE_MAX = 4
};

#define TXT_SPACERS 4



#endif // ENUMERATIONS_H
