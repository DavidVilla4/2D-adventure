#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "gf2d_sprite.h"
#include "gf2d_shape.h"
#include "gf2d_draw.h"
#include "gfc_color.h"

typedef struct Entity_S
{
	Color color;
	Rect box;
	Rect sword;
	Rect rock;
	Rect water;
	Rect ladder;
	Rect bounce;
	Rect lava;
	Rect enemy;
	Shape *testbox;
	Rect hitbox;
	Uint8 _inuse;
	Sprite *sprite;
	Vector2D position; //where the ent is in 2d space
	Vector2D velocity;//how fast the ent is
	float frame; //current frame for the sprite
	float maxFrame;
	float radius;
	//float velocity;
	void(*think)(struct Entity_S *self);
}Entity;
/**
*@brief get a pointer to a new entity
*@return NULL on out of memory error, a pointer to a blank entity otherwise
*/
Entity *entity_new();
/**
*@brief initialize the netity resource manager
*@note must be called before creating anew entity
*@param maxEnts upper bound of maximum concurrent entities to be supported
*/
void entity_manager_init(Uint32 maxEnts);
/**
*@brief free a previously allocated memory
*
*/

void entity_free(Entity *self);
void entity_update(Entity *self);
void entity_update_all();
void entity_draw_all();


#endif