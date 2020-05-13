#include "sign.h"

Entity *sign_new(Vector2D poisiton)
{
	Entity *self;
	self = entity_new();

	if (!self)
	{
		slog("no ent created");
		return NULL;
	}

	self->sprite = gf2d_sprite_load_image("images/signpost1.png");
	self->position.x = 700;
	self->position.y = 300;

	self->hitbox = gf2d_rect(self->position.x, self->position.y, 30, 50);

	self->new_sprite = gf2d_sprite_load_image("images/beer.png");
	return self;
}

void sign_update(Entity *self, Entity *player)
{
	const Uint8 *keys;
	keys = SDL_GetKeyboardState(NULL);
	//gf2d_rect_draw(self->hitbox, gfc_color(1, 0, 1, 1));

	if (collide_rect(self->hitbox, player->box))
	{
		if (keys[SDL_SCANCODE_L])
		{
			gf2d_sprite_draw_image(self->new_sprite, vector2d(100,100));
		}
	}
	
}

void sign_free(Entity *self);

void boss1_draw(Entity *self);