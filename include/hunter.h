#ifndef __HUNTER_H__
#define __HUNTER_H__
#include "entity.h"


Entity *hunter_new(Vector2D position);

void hunter_update(Entity *self, Entity *player);

void hunter_free(Entity *self);

void hunter_draw(Entity *self);


#endif