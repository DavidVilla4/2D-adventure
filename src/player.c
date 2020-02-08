#include "gfc_vector.h"
#include "entity.h"
#include "gf2d_sprite.h"
#include "simple_logger.h"
#include "gf2d_shape.h"
#include "gfc_color.h"
#include "player.h"

Entity *new_player(Vector2D position)
{
	Entity *self;
	slog("sent");
	self = entity_new();
	if (!self)return NULL;
	self->sprite = gf2d_sprite_load_all(
		"images/space_bug.png",
		128,
		128,
		16);
	
	///self->hitbox = gf2d_rect(position.x, position.y, 20, 35);
	self->box = gf2d_shape_rect(10, 10, 37, 25);
	return self;

}


void player_update(Entity *self)
{
	const Uint8 *keys;
	keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_A])self->position.x -= 3;
	if (keys[SDL_SCANCODE_D])self->position.x += 3;
	if (keys[SDL_SCANCODE_W])self->position.y -= 3;
	if (keys[SDL_SCANCODE_S])self->position.y += 3;

	entity_update(self);
	entity_draw(self);
	
	gf2d_shape_draw(self->box, gfc_color(0, 10, 0, 1), vector2d(0,0));
	self->box.s.c.x = self->position.x + 40;
	self->box.s.c.y = self->position.y + 50;

}

