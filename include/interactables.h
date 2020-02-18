#ifndef __INTERACTABLES_H__
#define __INTERACTABLES_H__
#include "entity.h"

Entity *new_rock(Vector2D position);

void rock_update(Entity *self);

void rock_free(Entity *self);

void rock_draw(Entity *self);

Entity *new_other();
#endif