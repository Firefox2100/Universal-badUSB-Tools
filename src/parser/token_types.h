#ifndef _TOKEN_TYPES_H
#define _TOKEN_TYPES_H

typedef enum TOKEN_TYPE{
    NONE,               //Empty type
    HOLD,               //Keyword hold
    RELEASE,            //Keyword release
    ALL,                //Keyword all
    STRING,             //Keyword string
    KEY,                //One key about to be pressed
    INT,                //An integer
    CONTENT,            //Content of a string
    FN,
    ESC,
    DELETE,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    PRTSCR,
    INSERT,
    BACKSPACE,
    ENTER,
    SHIFT,
    CAPSLOCK,
    CTRL,
    ALT,
    PGUP,
    PGDN,
    HOME,
    END,
    NUMLOCK,
    UP,
    DOWN,
    LEFT,
    RIGHT
}token_types;

#endif