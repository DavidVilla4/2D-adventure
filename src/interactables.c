#include "interactables.h"
#include "simple_logger.h"
#include "entity.h"

Entity *self;

Entity *new_rock(Vector2D position)
{
	self = entity_new();

	if (!self)
	{
		slog("no ent created");
		return NULL;
	}
	self->sprite = gf2d_sprite_load_all(
		"images/space_bug.png",
		128,
		128,
		16);
	
	self->box = gf2d_shape_rect(10, 10, 50, 25);
	return self;
}

void rock_update(Entity *self)
{
	gf2d_shape_draw(self->box, gfc_color(10, 0, 0, 1), vector2d(0, 0));
	entity_update(self);
	self->box.s.c.x = self->position.x + 30;
	self->box.s.c.y = self->position.y + 50;

}

void rock_free(Entity *self)
{
	if (!self)return;
	gf2d_sprite_free(self);
	free(self);
}

void rock_draw(Entity *self)
{
	if (!self)return;
	//gf2d_sprite_draw_image(level->background, vector2d(0, 0));

	gf2d_shape_draw(self->box, gfc_color(10, 0, 0, 1), vector2d(0, 0));

	//gf2d_draw_rect(level->bounds, vector4d(255, 0, 0, 255));
}