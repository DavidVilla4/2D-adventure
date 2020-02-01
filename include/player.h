#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "gfc_vector.h"
#include "entity.h"
#include "gf2d_sprite.h"
#include "simple_logger.h"


Entity *new_player(Vector2D position);

void player_update(Entity *self);


#endif