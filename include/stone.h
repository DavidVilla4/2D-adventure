#ifndef __STONE_H__
#define __STONE_H__
#include "player.h"
#include "entity.h"
#include "gf2d_sprite.h"
#include "simple_logger.h"

Entity *stone_new(Vector2D position);

void *stone_update(Entity *self, Entity *player);

void *stone_free(Entity *self);


#endif