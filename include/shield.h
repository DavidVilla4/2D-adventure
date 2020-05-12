#ifndef __SHIELD_H__
#define __SHIELD_H__

#include "entity.h"
#include "gf2d_sprite.h"
#include "simple_logger.h"

Entity *shield_new(Vector2D poisiton);

void shield_update(Entity *self, Entity *player);

void shield_free(Entity *self);

void shield_draw(Entity *self);

#endif