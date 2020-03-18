#ifndef __HEART_H__
#define __HEART_H__
#include "entity.h"

Entity *heart_new(Vector2D psoition);

void heart_update(Entity *self, Entity *player);

void heart_free(Entity *self);

void heart_draw(Entity *self);

#endif