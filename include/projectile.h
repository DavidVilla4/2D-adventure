#ifndef __PROJECTILE_H__
#define __PROJECTILE_H__
#include "simple_logger.h"
#include "entity.h"

Entity *projectile_new(Vector2D position);

void projectile_update(Entity *self);

void projectile_free(Entity *self);

void projectile_draw(Entity *self);

#endif