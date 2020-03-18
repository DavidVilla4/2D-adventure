#ifndef __HEALTH_BAR_H__
#define __HEALTH_BAR_H__
#include "entity.h"
#include "player.h"
#include <string.h>


Entity *health_new(Vector2D position);

void health_update(Entity *self, Entity *player);

void health_free(Entity *self);

void health_draw(Entity *self);

void bar_draw(Rect *self);

#endif