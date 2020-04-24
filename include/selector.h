#ifndef __SELECTOR_H__
#define __SELECTOR_H__
#include "entity.h"

Entity *sel_new(Vector2D position);

void sel_update(Entity *self);

void sel_free(Entity *self);

void sel_draw(Entity *self);

#endif