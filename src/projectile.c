#include "projectile.h"
#include "simple_logger.h"
#include "entity.h"
#include "player.h"
#define MAX_SHOTS 10	
Entity *shots[MAX_SHOTS] = { NULL };
Entity *projectile_new(Vector2D position, Entity *player)
{
	Entity *self;
	self = entity_new();

	if (!self)return NULL;
	self->box = gf2d_rect(player->box.x, player->box.y, 20, 20);
	//self->box = gf2d_rect(40, 40, 20, 20);
	
	return self;
}


void projectile_update(Entity *self, Entity *player)
{

	const Uint8 *keys;
	keys = SDL_GetKeyboardState(NULL);
	gf2d_rect_draw(self->box, gfc_color(10, 10, 0, 1));
	self->box.x += 1;
	if (keys[SDL_SCANCODE_I])
	{
		self->box.x -= 2;
	}
	

	entity_update(self);
	
}



void projectile_free(Entity *self)
{
	if (!self)return;
	gf2d_sprite_free(self);
	free(self);
}

void projectile_draw(Entity *self)
{
	if (!self)return;
	self->box.x += 1;
	gf2d_rect_draw(self->box, gfc_color(0, 10, 10, 1));
}