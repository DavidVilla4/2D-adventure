#include "stone.h"


Entity *stone_new(Vector2D position)
{
	Entity *self;
	self = entity_new();
	if (!self)
	{
		slog("no ent created");
		return NULL;
	}
	
	self->box = gf2d_rect(600, 200, 500, 128);
	self->hitbox = gf2d_rect(600, 550, 500, 128);
	return self;

}

void *stone_update(Entity *self, Entity *player)
{
	gf2d_rect_draw(self->box, gfc_color(1, 0, 0, 1), vector2d(0,0));
	gf2d_rect_draw(self->hitbox, gfc_color(1, 0, 0, 1), vector2d(0, 0));

	if (collide_rect(self->box, player->box))
	{
		player->velocity = vector2d(-10, 0);
	}

	if (collide_rect(self->hitbox, player->box))
	{
		player->velocity = vector2d(-10, 0);
	}



}

void *stone_free(Entity *self);