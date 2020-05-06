#ifndef __BOSS2_H__
#define __BOSS2_H__
#include "entity.h"
#include "gf2d_sprite.h"
#include "simple_logger.h"

Entity *boss2_new(Vector2D poisiton);

void boss2_update(Entity *self, Entity *player);

void boss2_free(Entity *self);

void boss2_draw(Entity *self);


#endif