#include "common.h"
#include "zlib/zutil.h"
#include "zlib/infblock.h"
#include "zlib/inflate.h"

// ZLIB_VERSION string ("1.0.4")
extern const char D_800F9430[];

extern inflate_blocks_statef *inflate_blocks_new(z_streamp, check_func, uInt);
extern void  inflate_blocks_reset(inflate_blocks_statef *, z_streamp, uLongf *);
extern int   inflate_blocks_free(inflate_blocks_statef *, z_streamp, uLongf *);
extern uLong func_800B74B0(uLong, const Bytef *, uInt); // adler32
extern voidpf func_800BDE58(voidpf, uInt, uInt);        // zcalloc
extern void   func_800BDE88(voidpf, voidpf);             // zcfree

// inflateReset
int func_800B9A70(z_streamp z) {
    uLong c;
    if (z == Z_NULL || z->state == Z_NULL)
        return Z_STREAM_ERROR;
    z->total_in = z->total_out = 0;
    z->msg = Z_NULL;
    z->state->mode = z->state->nowrap ? BLOCKS : METHOD;
    inflate_blocks_reset(z->state->blocks, z, &c);
    return Z_OK;
}

// inflateEnd
int func_800B9AE0(z_streamp z) {
    uLong c;
    if (z == Z_NULL || z->state == Z_NULL || z->zfree == Z_NULL)
        return Z_STREAM_ERROR;
    if (z->state->blocks != Z_NULL)
        inflate_blocks_free(z->state->blocks, z, &c);
    ZFREE(z, z->state);
    z->state = Z_NULL;
    return Z_OK;
}

// inflateInit2_
int func_800B9B60(z_streamp z, int w, const char *version, int stream_size) {
    if (version == Z_NULL || version[0] != D_800F9430[0] ||
        stream_size != sizeof(z_stream))
        return Z_VERSION_ERROR;
    if (z == Z_NULL)
        return Z_STREAM_ERROR;
    z->msg = Z_NULL;
    if (z->zalloc == Z_NULL) {
        z->zalloc = func_800BDE58;
        z->opaque = (voidpf)0;
    }
    if (z->zfree == Z_NULL)
        z->zfree = func_800BDE88;
    if ((z->state = (struct internal_state FAR *)
         ZALLOC(z, 1, sizeof(struct internal_state))) == Z_NULL)
        return Z_MEM_ERROR;
    z->state->blocks = Z_NULL;
    z->state->nowrap = 0;
    if (w < 0) {
        w = -w;
        z->state->nowrap = 1;
    }
    if (w < 8 || w > 15) {
        func_800B9AE0(z);
        return Z_STREAM_ERROR;
    }
    z->state->wbits = (uInt)w;
    if ((z->state->blocks =
         inflate_blocks_new(z, z->state->nowrap ? Z_NULL : func_800B74B0, (uInt)1 << w))
         == Z_NULL) {
        func_800B9AE0(z);
        return Z_MEM_ERROR;
    }
    func_800B9A70(z);
    return Z_OK;
}

// inflateInit_
int func_800B9CC4(z_streamp z, const char *version, int stream_size) {
    return func_800B9B60(z, DEF_WBITS, version, stream_size);
}
