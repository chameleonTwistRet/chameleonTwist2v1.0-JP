#ifndef _ENUMS_H_
#define _ENUMS_H_

enum TongueState {
    TONGUE_IDLE = 0,
    TONGUE_EXTENDING = 1,
    TONGUE_RETRACTION = 3,
    TONGUE_VAULT = 4,
    TONGUE_VAULT_ROCK = 5, //also used in a neutral vault, unsure how to name
    TONGUE_RELEASE_FROM_VAULT = 6,
    TONGUE_CONTACT_WALL = 7,
    TONGUE_RETRACTION = 9,
    TONGUE_STICK_WALL = 11,
    TONGUE_RELEASE_RETRACTION = 12,
};

#endif //_ENUMS_H_