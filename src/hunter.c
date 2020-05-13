#include "hunter.h"
#include "simple_logger.h"
#include "player.h"
#include "gf2d_sprite.h"

Entity *self;

Entity *hunter_new(Vector2D position)
{
	self = entity_new();
	if (!self)
	{
		slog("hunter not set");
		return NULL;
	}
	//self->sprite = gf2d_sprite_load_all("images/terrex.png", 95, 80,1);
	self->position.x = 100;
	self->position.y = 100;
	self->enemy=gf2d_rect(100, 100, 20, 20);
	return self;
}

void hunter_update(Entity *self, Entity *player)
{

	gf2d_rect_draw(self->enemy, gfc_color(1, 0, 0, 1));
	//gf2d_sprite_draw_image(self->sprite, vector2d(self->enemy.x, self->enemy.y));
	
	if (player->position.x+50 - self->enemy.x<0)//less that if creature is to the right of player
	{
		self->enemy.x -= .3;
	}
	else
	{
		self->enemy.x += .3;
	}
	if (player->position.y+50 - self->enemy.y < 0)
	{
		self->enemy.y -= .3;
	}
	else
	{
		self->enemy.y += .3;
	}
	
}
void hunter_free(Entity *self)
{
	if (!self)return;
	gf2d_sprite_free(self);
	free(self);
}

void hunter_draw(Entity *self)
{
	if (!self)return;
	gf2d_rect_draw(self->enemy, gfc_color(10, 0, 0, 1));
}