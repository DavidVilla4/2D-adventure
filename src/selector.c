#include "selector.h"
#include "simple_logger.h"


Entity *sel_new(Vector2D position)
{
	Entity *self;
	self = entity_new();
	if (!self)return NULL;
	self->box = gf2d_rect(350, 230, 20, 20);
	
	return self;

}

void sel_update(Entity *self)
{
	gf2d_rect_draw(self->box, gfc_color(1, 0, 0, 1));
	gf2d_rect_draw(self->hitbox, gfc_color(0, 0, 1, 1));
	const Uint8 *keys;
	keys = SDL_GetKeyboardState(NULL);
	


	if (keys[SDL_SCANCODE_O])
	{
		vector2d_set(self->box, 350, 430);
	}
	else if (keys[SDL_SCANCODE_L])
	{
		vector2d_set(self->box, 350, 230);
	}


	if (keys[SDL_SCANCODE_0])
	{
		Level2();
	}
}