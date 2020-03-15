#ifndef __PROJECTILE_H__
#define __PROJECTILE_H__
#include "entity.h"
#include "player.h"

Entity *projectile_new(Vector2D position, Entity *player);

void projectile_update(Entity *self, Entity *player);

void projectile_free(Entity *self);

void projectile_draw(Entity *self);

#endif