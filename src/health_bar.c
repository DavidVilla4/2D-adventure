#include "health_bar.h"
#include "simple_logger.h"
#include "player.h"

Entity *health_new(Vector2D position)
{
	Entity *self;
	self = entity_new();
	if (!self)return NULL;
	self->box = gf2d_rect(25, 10, 20, 50);
	self->lava = gf2d_rect(0, 10, 20, 50);
	self->health1 = gf2d_rect(50, 10, 20, 50);
	/*
	for (int i = 0; i < 100; i+=10)
	{
		slog("i %d", i);
		self->box = gf2d_rect(0, 10, 50, 50);
		self->box = gf2d_rect(10, 10, 50, 50);
		if (i >= 10)
		{
			break;
		}
	}
	*/
	return self;
}

void health_update(Entity *self, Entity *player)
{
	gf2d_rect_draw(self->box, gfc_color(10, 0, 0, 1));
	gf2d_rect_draw(self->lava, gfc_color(10, 0, 0, 1));
	gf2d_rect_draw(self->health1, gfc_color(10, 0, 0, 1));
	if (player->dead == true)
	{
		gf2d_rect_draw(self->health1, gfc_color(0, 0, 0, 1));
	}
}
void health_free(Entity *self);

void health_draw(Entity *self);