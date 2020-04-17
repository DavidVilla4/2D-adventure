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
	self->rock_sprite = gf2d_sprite_load_all("images/rock.png", 50, 30, 0);
	self->water_sprite = gf2d_sprite_load_all("images/water.jpg", 100, 150, 0);
	self->ladder_sprite = gf2d_sprite_load_all("images/accessories/ladder.png", 100, 200, 0);
	self->rock = gf2d_rect(300, 500, 50, 25);
	self->water = gf2d_rect(200, 80, 100, 150);
	self->ladder = gf2d_rect(200, 300, 50, 100);
	self->lava = gf2d_rect(150, 400, 100, 100);
	self->hitbox = gf2d_rect(100, 100, 10, 100);
	self->heart = gf2d_rect(400, 100, 30, 25);
	
	return self;
}

void rock_update(Entity *self)
{
	//Entity *water;
	//gf2d_rect_draw(self->rock, gfc_color(10, 0, 0, 1), vector2d(0, 0));
	//gf2d_rect_draw(water->water, gfc_color(0, 0, 10, 1), vector2d(0, 0));
	entity_update(self);
	gf2d_rect_draw(self->rock, gfc_color(10, 0, 0, 1), vector2d(0, 0));
	gf2d_rect_draw(self->water, gfc_color(0, 0, 10, 1), vector2d(0, 0));
	gf2d_rect_draw(self->ladder, gfc_color(0, 20, 0, 1), vector2d(0, 0));
	gf2d_rect_draw(self->lava, gfc_color(20, 0, 0, 1), vector2d(0, 0));
	gf2d_rect_draw(self->hitbox, gfc_color(1, 1, 0, 1), vector2d(0, 0));
	gf2d_rect_draw(self->heart, gfc_color(1, 1, 0, 1, vector2d(0, 0)));
	gf2d_sprite_draw_image(self->rock_sprite, vector2d(self->rock.x, self->rock.y));
	gf2d_sprite_draw_image(self ->water_sprite, vector2d(self->water.x, self->water.y));
	gf2d_sprite_draw_image(self->ladder_sprite, vector2d(self->ladder.x-20, self->ladder.y));
	//self->box.x = self->position.x + 50;
	//self->box.y = self->position.y + 50;

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
	gf2d_rect_draw(self->rock, gfc_color(10, 0, 0, 1), vector2d(0, 0));
	gf2d_rect_draw(self->water, gfc_color(0, 0, 10, 1), vector2d(0, 0));
	gf2d_rect_draw(self->ladder, gfc_color(0, 20, 0, 1), vector2d(0, 0));
	gf2d_rect_draw(self->ladder, gfc_color(20, 0, 0, 1), vector2d(0, 0));
	gf2d_rect_draw(self->hitbox, gfc_color(1, 1, 0, 1), vector2d(0, 0));
	gf2d_rect_draw(self->heart, gfc_color(1, 1, 0, 1, vector2d(0, 0)));
	//gf2d_draw_rect(level->bounds, vector4d(255, 0, 0, 255));
}