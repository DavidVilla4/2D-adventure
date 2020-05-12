#include "shield.h"

Entity *shield_new(Vector2D poisiton)
{
	Entity *self;
	self = entity_new();

	if (!self)
	{
		slog("no ent created");
		return NULL;
	}

	self->sprite = gf2d_sprite_load_image("images/shield5.png");
	self->position.x = 600;
	self->position.y = 300;

	self->box = gf2d_rect(self->position.x, self->position.y, 40, 40);
	return self;
}

void shield_update(Entity *self, Entity *player)
{
	gf2d_rect_draw(self->box, gfc_color(1, 0, 0, 1));
}

void shield_free(Entity *self);

void shield_draw(Entity *self);