#ifndef __BOSS1_H__
#define __BOSS1_H__

#include "entity.h"

Entity *boss1_new(Vector2D poisiton);

void boss1_update(Entity *self, Entity *player);

void boss1_free(Entity *self);

void boss1_draw(Entity *self);



#endif