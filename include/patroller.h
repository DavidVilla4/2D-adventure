#ifndef __PATROLLER_H__
#define __PATROLLER_H__
#include "entity.h"
Entity *patroller_new(Vector2D position);

void patroller_update(Entity *self, Entity *player);

void patroller_free(Entity *self);

void patroller_draw(Entity *self);

#endif