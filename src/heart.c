#include "heart.h"
#include "simple_logger.h"
#include "player.h"

Entity *heart_new(Vector2D psoition)
{
	Entity *self;
	self = entity_new();
	if (!self)return NULL;
	self->heart_sprite = gf2d_sprite_load_all("images/heartsm.png",32,32,0);
	self->heart = gf2d_rect(400, 100, 30, 25);
	return self;
}

void heart_update(Entity *self, Entity *player)
{
	
	gf2d_rect_draw(self->heart, gfc_color(1, 1, 0, 1));
	gf2d_sprite_draw_image(self->heart_sprite, vector2d(self->heart.x, self->heart.y));
	//slog("pickup %d", player->pickup);
	if (player->pickup==true)
	{
		if (player->dead == true)
		{
			
			gf2d_rect_draw(self->heart, gfc_color(0, 0, 0, 1));
		}
		
	}
	entity_update(self);
}

void heart_free(Entity *self)
{
	if (!self)return;
	gf2d_sprite_free(self);
	free(self);
}

void heart_draw(Entity *self)
{
	if (!self)return;
	gf2d_rect_draw(self->heart, gfc_color(1, 1, 10, 0));
}