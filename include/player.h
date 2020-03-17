#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "gfc_vector.h"
#include "entity.h"
#include "gf2d_sprite.h"
#include "simple_logger.h"
#include "level.h"


typedef struct
{
	Vector2D velocity;
	Bool left;
	
}Player;

Vector2D *player_set_position(Vector2D position);

void player_think(Entity *self);

Entity *new_player(Vector2D position);

void player_update(Entity *self, Level *level, Entity *rock, Entity *water);

void player_free(Entity *self);


#endif