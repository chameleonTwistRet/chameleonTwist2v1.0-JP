#include "common.h"
#include "zutil.h"
#include "inftrees.h"

char inflate_copyright[] = " inflate 1.0.4 Copyright 1995-1996 Mark Adler ";
/*
  If you use the zlib library in a product, an acknowledgment is welcome
  in the documentation of your product. If for some reason you cannot
  include such an acknowledgment, I would appreciate that you keep this
  copyright string in the executable of your product.
 */
struct internal_state  {int dummy;}; /* for buggy compilers */

/* simplify the use of the inflate_huft type with some defines */
#define base more.Base
#define next more.Next
#define exop word.what.Exop
#define bits word.what.Bits


extern int huft_build OF((
    uIntf *,            /* code lengths in bits */
    uInt,               /* number of codes */
    uInt,               /* number of "simple" codes */
    uIntf *,            /* list of base values for non-simple codes */
    uIntf *,            /* list of extra bits for non-simple codes */
    inflate_huft * FAR*,/* result: starting table */
    uIntf *,            /* maximum lookup bits (returns actual) */
    z_streamp ));       /* for zalloc function */

local voidpf falloc OF((
    voidpf,             /* opaque pointer (not used) */
    uInt,               /* number of items */
    uInt));             /* size of item */

/* Tables for deflate from PKZIP's appnote.txt. */
local uInt cplens[31] = { /* Copy lengths for literal codes 257..285 */
        3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
        35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258, 0, 0};
        /* actually lengths - 2; also see note #13 above about 258 */
local uInt cplext[31] = { /* Extra bits for literal codes 257..285 */
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
        3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0, 192, 192}; /* 192==invalid */
local uInt cpdist[30] = { /* Copy offsets for distance codes 0..29 */
        1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
        257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145,
        8193, 12289, 16385, 24577};
local uInt cpdext[30] = { /* Extra bits for distance codes */
        0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
        7, 7, 8, 8, 9, 9, 10, 10, 11, 11,
        12, 12, 13, 13};

extern int huft_build OF((
    uIntf *,            /* code lengths in bits */
    uInt,               /* number of codes */
    uInt,               /* number of "simple" codes */
    uIntf *,            /* list of base values for non-simple codes */
    uIntf *,            /* list of extra bits for non-simple codes */
    inflate_huft * FAR*,/* result: starting table */
    uIntf *,            /* maximum lookup bits (returns actual) */
    z_streamp ));       /* for zalloc function */

extern int inflate_trees_free OF((
    inflate_huft *,             /* tables to free */
    z_streamp ));               /* for zfree function */

int inflate_trees_bits(c, bb, tb, z)
uIntf *c;               /* 19 code lengths */
uIntf *bb;              /* bits tree desired/actual depth */
inflate_huft * FAR *tb; /* bits tree result */
z_streamp z;            /* for zfree function */
{
  int r;

  r = huft_build(c, 19, 19, (uIntf*)Z_NULL, (uIntf*)Z_NULL, tb, bb, z);
  if (r == Z_DATA_ERROR)
    z->msg = (char*)"oversubscribed dynamic bit lengths tree";
  else if (r == Z_BUF_ERROR)
  {
    inflate_trees_free(*tb, z);
    z->msg = (char*)"incomplete dynamic bit lengths tree";
    r = Z_DATA_ERROR;
  }
  return r;
}

int inflate_trees_dynamic(nl, nd, c, bl, bd, tl, td, z)
uInt nl;                /* number of literal/length codes */
uInt nd;                /* number of distance codes */
uIntf *c;               /* that many (total) code lengths */
uIntf *bl;              /* literal desired/actual bit depth */
uIntf *bd;              /* distance desired/actual bit depth */
inflate_huft * FAR *tl; /* literal/length tree result */
inflate_huft * FAR *td; /* distance tree result */
z_streamp z;            /* for zfree function */
{
  int r;

  /* build literal/length tree */
  if ((r = huft_build(c, nl, 257, cplens, cplext, tl, bl, z)) != Z_OK)
  {
    if (r == Z_DATA_ERROR)
      z->msg = (char*)"oversubscribed literal/length tree";
    else if (r == Z_BUF_ERROR)
    {
      inflate_trees_free(*tl, z);
      z->msg = (char*)"incomplete literal/length tree";
      r = Z_DATA_ERROR;
    }
    return r;
  }

  /* build distance tree */
  if ((r = huft_build(c + nl, nd, 0, cpdist, cpdext, td, bd, z)) != Z_OK)
  {
    if (r == Z_DATA_ERROR)
      z->msg = (char*)"oversubscribed literal/length tree";
    else if (r == Z_BUF_ERROR) {
#ifdef PKZIP_BUG_WORKAROUND
      r = Z_OK;
    }
#else
      inflate_trees_free(*td, z);
      z->msg = (char*)"incomplete literal/length tree";
      r = Z_DATA_ERROR;
    }
    inflate_trees_free(*tl, z);
    return r;
#endif
  }

  /* done */
  return Z_OK;
}

#pragma GLOBAL_ASM("asm/nonmatchings/zlib/inftrees/func_800BAD7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/zlib/inftrees/func_800BADA4.s")

int inflate_trees_free(t, z)
inflate_huft *t;        /* table to free */
z_streamp z;            /* for zfree function */
/* Free the malloc'ed tables built by huft_build(), which makes a linked
   list of the tables it made, with the links in a dummy first entry of
   each table. */
{
  register inflate_huft *p, *q, *r;

  /* Reverse linked list */
  p = Z_NULL;
  q = t;
  while (q != Z_NULL)
  {
    r = (q - 1)->more.Next;
    (q - 1)->more.Next = p;
    p = q;
    q = r;
  }
  /* Go through linked list, freeing from the malloced (t[-1]) address. */
  while (p != Z_NULL)
  {
    q = (--p)->more.Next;
    ZFREE(z,p);
    p = q;
  } 
  return Z_OK;
}

s32 D_800F06C8[] = {0, 0}; //?
