#ifndef __SIGN_H__
#define __SIGN_H__

#include "entity.h"
#include "gf2d_sprite.h"
#include "simple_logger.h"

Entity *sign_new(Vector2D poisiton);

void sign_update(Entity *self, Entity *player);

void sign_free(Entity *self);

void boss1_draw(Entity *self);

#endif