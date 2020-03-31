#ifndef __PROJECTILE_H__
#define __PROJECTILE_H__
#include "entity.h"
#include "player.h"

Entity *projectile_new(Vector2D position, Entity *player);



Entity *proj_up(Vector2D position, Entity *player);

Entity *proj_down(Vector2D position, Entity *player);

void projectile_update(Entity *self, Entity *player);

void update_right(Entity *self);



void update_down(Entity *self);

void update_up(Entity *self);

void projectile_free(Entity *self);

void projectile_draw(Entity *self);

#endif