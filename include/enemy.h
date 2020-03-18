#ifndef __ENEMY_H__
#define	__ENEMY_H__
#include "entity.h"

Entity *enemy_new(Vector2D poisiton);

void enemy_update(Entity *self);

void enemy_free(Entity *self);

void enemy_draw(Entity *self);


#endif