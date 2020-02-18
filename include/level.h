#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "gfc_types.h"
#include "gf2d_sprite.h"
#include "gf2d_shape.h"


typedef struct
{
	Sprite *background;
	Shape bounds;
}Level;


Level *level_new();
void level_free(Level *level);
void level_draw(Level *level);
Level *level_get_active();

/**
* @brief test if a circle is touching or exceeding the level bounds
*/
Uint8 level_bounds_test_circle(Level *level, Vector2D center, float radius, Vector2D *normal);

//Uint8 level_bounds_test_rect(Level *level, Vector2D center, float w, float h);

#endif