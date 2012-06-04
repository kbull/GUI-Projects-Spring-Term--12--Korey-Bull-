#ifndef ENUMERATIONS_H
#define ENUMERATIONS_H

// fixed main window dimensions
#define MW_WIDTH 600
#define MW_HEIGHT 800


// fixed clock-view dimensions
#define VIEW_WIDTH 480
#define VIEW_HEIGHT 600

// clock views
enum ViewMode
{
    ANALOG = 0,
    DIGITAL = 1,
    BINARY = 2,
    VMODE_MAX = 3
};

// Clock Digits - format based
#define BCD_CNT 6
#define DEC_CNT 3


// user input/ctrl buttons
typedef enum UserButtons
{
    PREVIOUS = 0,
    NEXT = 1,
    USRBTTN_MAX = 2
} UserButtons;


#endif // ENUMERATIONS_H
