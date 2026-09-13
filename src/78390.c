#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/78390/func_8009CF90.s")

#define NULL 0

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
s16 func_800ABCE4(Actor *actor);
void func_800ABF4C(Actor *actor, f32 arg1);
void func_8009D39C(Actor *actor);

extern s16 D_80160632;   /* battle phase */
extern f32 D_8016063C;   /* boss health ratio, 1.0 -> 0.0 */
extern f32 D_8018A498;   /* target/lock-on position */
extern f32 D_8018A49C;
extern f32 D_8018A4A0;

#ifdef NON_MATCHING
void func_8009D39C(Actor *actor) {
    BossWork *work;
    f32 invHealth;
    f32 limit;
    f32 target;
    f32 prev;
    s16 scatter;
    s32 done;
    s16 oldState;
    s16 i;
    s32 odd;

    work = actor->work;

    if (D_80160632 != 3) {
        actor->unk_EA = 1;
    } else {
        actor->unk_EA = 0;
        func_800ABCB0(actor);
        func_800ABF4C(actor, 160.0f);
    }

    if (actor->unk_E0 > 0) {
        func_800ABCE4(actor);
        D_8016063C = actor->health / (f32)work->hpMax;
        oldState = work->state;
        invHealth = 1.0 - D_8016063C;
        work->moveSpeed = (((f32)work->moveSpeedBase * invHealth) * 0.5) + work->moveSpeedBase;
        work->childSpeed = (((f32)work->childSpeedBase * invHealth) * 0.8) + work->childSpeedBase;
        work->unk_24 = (work->unk_28 * D_8016063C) + 3.0f;
        work->unk_2C = (work->unk_30 * D_8016063C) + 20.0f;

        if (oldState != 4) {
            work->state = 4;
            work->savedState = oldState;
            actor->unk_80 = 1;
        } else {
            actor->animFrame = 0.0f;
        }

        if (D_8016063C <= 0.0f) {
            func_8003B8B8(0x28);
            D_8016063C = 0.0f;
            work->spinTimer = -1;
            work->state = 6;
            work->timer = 0.0f;
            work->stateLen = 0.0f;
            work->spin = 0.0f;
            D_80160632 = 0xA;
        }

        func_8003B96C(func_8003B914(5, &actor->posX, &actor->posY, &actor->posZ, 0x30), 0.35f);
    }

    if ((D_80160632 == 2) && (work->state == -1)) {
        work->state = 0;
    }
    if ((D_80160632 == 3) && (work->state == -2)) {
        work->state = 3;
    }

    if ((D_80160632 == 5) && (work->spawned == 0)) {
        for (i = 1; i < 8; i++) {
            if (work->children[i] != NULL) {
                func_8002A164(work->children[i]);
            }
        }

        actor->posX = (f32)work->homeX;
        work->homeY = work->baseY;
        actor->posY = work->heightOfs + (f32)work->homeY;
        actor->posZ = (f32)work->homeZ;
        work->spinTimer = -1;
        work->spin = 0.0f;

        for (i = 1; i < 8; i++) {
            work->children[i] = func_8009E108(actor, i);
        }

        work->state = 3;
        actor->unk_80 = 0;
        actor->animFrame = 0.0f;
        func_800375D4(actor, 1.0f);
        actor->facing = actor->yaw =
            func_8003CDD0(gPlayers[0].pos.x - actor->posX, gPlayers[0].pos.z - actor->posZ);
        work->spawned = 1;
        work->timer = 0.0f;
        work->stateLen = 0.0f;
    }

    if ((D_80160632 != 5) && (work->spawned == 1)) {
        work->spawned = 0;
    }

    actor->groundY = work->heightOfs + (f32)work->homeY;

    switch (actor->mode) {
    case 0:
        switch (work->state) {
        case 0:
            if (work->timer == 0.0f) {
                work->hopTimer = 8;
                work->timer = 1.0f;
            }
            if (work->hopTimer == 0) {
                target = actor->groundY;
                if (target < actor->posY) {
                    actor->posY -= 50.0f;
                    if (actor->posY <= target) {
                        actor->posY = work->heightOfs + (f32)work->homeY;
                        work->hopTimer--;
                        func_8003B8B8(0x46);
                    }
                }
            }
            if ((work->hopTimer < 0) && (func_800375D4(actor, 1.0f) == 1)) {
                work->state = -2;
                actor->unk_80 = 0;
                func_800375D4(actor, 1.0f);
            }
            if (actor->animFrame == 56.0f) {
                func_8003B914(0x17, &actor->posX, &actor->posY, &actor->posZ, 0x10);
            }
            break;

        case 3:
            done = 0;
            if (work->timer >= 30.0f) {
                done = 1;
            }
            work->timer += 1.0f;
            if (done != 0) {
                work->state = 1;
                work->timer = 0.0f;
            }
            break;

        case 5:
            done = 0;
            if (work->timer >= 30.0f) {
                done = 1;
            }
            work->timer += 1.0f;
            if (done != 0) {
                work->state = 1;
                work->timer = 0.0f;
                actor->animFrame = 0.0f;
            }
            break;

        case 1:
            actor->facing = func_800ABA58(actor, 5.0f);
            actor->posX += sin_deg(actor->facing) * work->moveSpeed;
            actor->posZ += cos_deg(actor->facing) * work->moveSpeed;

            if (actor->posX < (f32)(work->minX + 100)) {
                actor->posX = (f32)(work->minX + 100);
            }

            if ((f32)(work->maxX - 100) < actor->posX) {
                actor->posX = (f32)(work->maxX - 100);
            }

            if (actor->posZ < (f32)(work->minZ + 100)) {
                actor->posZ = (f32)(work->minZ + 100);
            }

            if ((f32)(work->maxZ - 100) < actor->posZ) {
                actor->posZ = (f32)(work->maxZ - 100);
            }

            if (work->timer == 0.0f) {
                work->stateLen = Random(50, 180);
            }
            done = 0;
            if (work->stateLen <= work->timer) {
                done = 1;
            }
            work->timer += 1.0f;
            if (done != 0) {
                work->state = 2;
                work->timer = 0.0f;
                work->stateLen = 0.0f;
            }

            if (actor->posY < actor->groundY) {
                actor->posY += 5.0f;
                if (actor->groundY <= actor->posY) {
                    actor->posY = actor->groundY;
                }
            }
            func_800375D4(actor, (s32)work->moveSpeed * 0.125);
            break;

        case 2:
            if (work->spin < 30.0f) {
                work->spin += 1.0f;
            }
            actor->facing += work->spin;
            if (work->spin == 28.0f) {
                work->spinTimer = 7;
            }
            if (work->spinTimer == 0) {
                work->spinTimer = -1;
                work->spin = 0.0f;
                for (i = 1; i < 8; i++) {
                    work->children[i] = func_8009E108(actor, i);
                }
                work->homeY = work->baseY;
                actor->unk_EA = 0;
                work->state = 1;
            }

            target = actor->groundY;
            if (target < actor->posY) {
                actor->posY -= 5.0f;
                if (actor->posY <= target) {
                    actor->posY = target;
                }
            }
            func_800375D4(actor, 1.0f);
            break;

        case 4:
            if (func_800375D4(actor, 1.0f) == 1) {
                work->state = work->savedState;
                actor->unk_80 = 0;
                func_800375D4(actor, 1.0f);
            }
            break;
        }
        break;

    case 2:
        if (work->spin < 60.0f) {
            work->spin += 0.5;
        }
        actor->facing += work->spin;

        if (work->spin >= 58.0f) {
            for (i = 0; i < 9; i++) {
                if ((work->children[i] != NULL) && (work->children[i]->unk_AC == 0.0f)) {
                    if (work->timer == 0.0f) {
                        work->children[i]->yaw = Random(0, 359);
                        if (i == 0) {
                            func_8003B8B8(0x2D);
                        }
                        work->savedX = actor->posX;
                        work->savedY = actor->posY;
                        work->savedZ = actor->posZ;
                        D_80160632 = 7;
                    }
                    work->children[i]->posX +=
                        sin_deg(work->children[i]->yaw) * work->childSpeed;
                    work->children[i]->posZ +=
                        cos_deg(work->children[i]->yaw) * work->childSpeed;
                }
            }
            work->timer += 1.0f;
        }

        if (work->timer == 0.0f) {
            func_8002D58C(actor->posX, actor->posY, actor->posZ, 1500.0f);

            //TODO: matching hack
            if ((!(((s32) work->stateLen) & 1)) ^ 0) {
                odd = (!((s32)work->stateLen & 1));
            } else {
                odd = (!((s32)work->stateLen & 1));
            }
            work->stateLen += 1.0f;
            if (odd) {
                work->savedX = actor->posX;
                work->savedY = actor->posY;
                work->savedZ = actor->posZ;

                actor->posX = Random((actor->posX - 250.0f), (actor->posX + 250.0f));
                actor->posY = Random((actor->posY - 300.0f), (actor->posY + 120.0f));
                actor->posZ = Random((actor->posZ - 250.0f), (actor->posZ + 250.0f));

                scatter = Random(5, 15);
                func_800AADE8(actor, scatter, scatter, scatter, 160.0f, 160.0f, 160.0f, 0x1E);
                if (Random(0, 2) == 0) {
                    func_8003B8B8(0x27);
                }

                actor->posX = work->savedX;
                actor->posY = work->savedY;
                actor->posZ = work->savedZ;
                if (Random(0, 8) == 0) {
                    func_8003B8B8(0x28);
                }

                if (Random(0, 4) == 0) {
                    work->savedY = actor->posY;
                    actor->posY -= 300.0f;
                    func_800AADE8(actor, 30.0f, 30.0f, 30.0f, 160.0f, 160.0f, 160.0f, 0x1E);
                    actor->posY = work->savedY;
                }
            }
        } else {
            func_8002D58C(work->savedX, work->savedY, work->savedZ, 4000.0f);
        }

        if (func_800375D4(actor, 1.0f) == 1) {
            actor->animFrame = 0.0f;
        }
        break;
    }

    actor->renderY = actor->posY;
    actor->renderX = actor->posX;
    actor->renderZ = actor->posZ;
    D_8018A498 = (f32)work->homeX;
    D_8018A49C = (f32)(work->homeY + 200);
    D_8018A4A0 = (f32)work->homeZ;
    func_800B4B50(actor->posX, actor->posY + 200.0f, actor->posZ);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/78390/func_8009D39C.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/78390/func_8009E108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/78390/func_8009E2A4.s")
