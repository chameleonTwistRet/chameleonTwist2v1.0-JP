/* inflate.h, shared by inflate.c and 94E70.c */

typedef enum {
    METHOD, FLAG, DICT4, DICT3, DICT2, DICT1, DICT0,
    BLOCKS,
    CHECK4, CHECK3, CHECK2, CHECK1,
    DONE, BAD
} inflate_mode;

struct internal_state {
    inflate_mode           mode;
    int                    method;
    union { uLong adler; uLong marker; } sub;
    int                    nowrap;
    uInt                   wbits;
    inflate_blocks_statef *blocks;
};
