#ifndef __GF2D_WINDOW_H__
#define __GF2D_WINDOW_H__
#include "gf2d_sprite.h"
#include "gf2d_shape.h"
#include "entity.h"
#include <SDL.h>
#include <stdio.h>

typedef struct Window_S
{
	Sprite *background; /*background image*/
}Window;

SDL_Window window_new(SDL_Window *window, Entity *player);

#endif