#include "gfc_vector.h"
#include "entity.h"
#include "gf2d_sprite.h"
#include "simple_logger.h"
#include "player.h"

Entity *new_player(Vector2D position)
{
	Entity *self;
	slog("sent");
	self = entity_new();
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

}

