#include "common.h"

typedef struct UnkD801606D0 {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ void (*unk_10)(struct UnkD801606D0 *);
} UnkD801606D0;

typedef struct UnkD80160808 {
    /* 0x00 */ s32 unk_00;
    /* 0x02 */ char unk_04[0x8];
    /* 0x0C */ s32 unk_0C;
} UnkD80160808;

extern Actor *gGtActionHead;      /* list head sentinel */
extern Actor *D_80160800;         /* list tail sentinel */
extern UnkD801606D0 D_801606D0;
extern UnkD80160808 D_80160808;
extern s16 D_800EAECC;
extern s16 D_80160818;            /* live actor count */
extern s16 D_80160632;            /* battle phase */
extern f32 D_8016063C;            /* boss health ratio */
extern f32 D_8018A498;
extern f32 D_8018A49C;
extern f32 D_8018A4A0;

void func_80027D94(Actor *actor);
void func_80027E98(Actor *actor);
void func_80027EA8(Actor *actor);
void func_8002A088(Actor *actor);
s32 func_8005524C(s16 id);
void func_800AA720(Actor *actor);

/* math / rng */
s32 Random(s32 min, s32 max);
f32 sin_deg(f32 deg);
f32 cos_deg(f32 deg);
f32 func_8003CDD0(f32 dx, f32 dz);              /* yaw from a 2D delta */
 
/* actors */
void func_8002A164(Actor *actor);               /* free / despawn */
Actor *func_8009E108(Actor *parent, s16 index); /* spawn child */
s32 func_800375D4(Actor *actor, f32 speed);     /* advance anim; 1 when it ends */
 
/* camera / screen */
void func_8002D58C(f32 x, f32 y, f32 z, f32 radius);
void func_800B4B50(f32 x, f32 y, f32 z);
 
/* sound / effects */
void func_8003B8B8(s32 soundId);
s32 func_8003B914(s32 effectId, f32 *x, f32 *y, f32 *z, s32 arg4);
void func_8003B96C(s32 effectHandle, f32 scale);
void func_800AADE8(Actor *actor, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, s32 arg7);
 
/* boss helpers */
f32 func_800ABA58(Actor *actor, f32 turnRate);  /* turn toward target, returns yaw */
void func_800ABCB0(Actor *actor);
void func_800ABCE4(Actor *actor);
void func_800ABF4C(Actor *actor, f32 arg1);
void func_8009D39C(Actor *actor);

#pragma GLOBAL_ASM("asm/nonmatchings/4E90/func_80029A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4E90/func_80029BD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4E90/func_80029C24.s")

void func_80029C44(void) {
    Actor *actor;
    Actor *next;
    s32 i;

    actor = gGtActionHead->next;
    while (1) {
        if ((actor == D_80160800)) {
            break;
        }
        if ((actor->unk_E4 > 0) && (func_8005524C(actor->unk_E4) == 0)) {
            func_8002A164(actor);
        }

        if (actor->unk_120 == 1) {
            if (((actor->unk_4A >= D_80160808.unk_00) || (D_80160808.unk_0C != 0)) &&
                (actor->unk_122 != 0)) {
                if (actor->func != NULL) {
                    if (actor->unk_54 == 0xC351) { //50,001
                        func_80027E98(actor);
                        actor->func(actor);
                        func_80027EA8(actor);
                    } else if (actor->unk_54 == 0x9C40) { //40,000
                        func_80027D94(actor);
                    } else {
                        actor->func(actor);
                    }
                }
            }

            if ((D_800EAECC == 1) && (actor->unk_A4 > 0.0f) && (actor->unk_A0 > 0.0f) &&
                (((actor->unk_DC == 2)) || (actor->unk_DC == 1)) &&
                !(actor->unk_F2 & 1)) {
                func_800AA720(actor);
            }
            actor = actor->next;
        } else {
            next = actor->next;
            if (actor->func2 != NULL) {
                actor->func2(actor);
            } else {
                func_8002A088(actor);
            }
            actor = next;
        }        
    }

    i = 0;
    actor = gGtActionHead->next;
    while (1) {
        if (actor == D_80160800) {
            break;
        }
        next = actor;
        actor->unk_120 = actor->unk_122;
        actor = actor->next;
 
        if (next->unk_120 == 0) {
            if (next->func2 != NULL) {
                next->func2(next);
            } else {
                func_8002A088(next);
            }
        }
        i++;
    }

    D_80160818 = i;
    D_80160808.unk_0C = 0;

    if (D_801606D0.unk_10 != NULL) {
        D_801606D0.unk_10(&D_801606D0);
    }
}


// gtActionSpawn (?)
#pragma GLOBAL_ASM("asm/nonmatchings/4E90/func_80029EB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4E90/func_8002A088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4E90/func_8002A164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4E90/func_8002A178.s")
