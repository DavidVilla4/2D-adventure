#include "patroller.h"

#include "simple_logger.h"
#include "gf2d_sprite.h"

Entity *self;
static float timer = 0.0f;
static float frameIncr = 0.0f;
static frame = { 0 };
Entity *patroller_new(Vector2D position)
{
	self = entity_new();

	if (!self)
	{
		slog("no ent created");
		return NULL;
	}

	self->fire_sprite = gf2d_sprite_load_all(
		"images/pumpkin_monster.png",
		35,
		60,
		4);
	self->frame = 1;
	self->position.x = 100;
	self->position.y = 100;
	self->enemy=gf2d_rect(self->position.x, self->position.y, 50, 50);
	return self;
}

void patroller_update(Entity *self)
{
	int distance;
	timer += 0.1f;
	gf2d_rect_draw(self->enemy, gfc_color(0, 0, 1, 1));
	gf2d_sprite_draw_image(self->fire_sprite, vector2d(self->enemy.x, self->enemy.y-15));
	frameIncr += 0.1f;
	if (frameIncr > 4.0f)
	{
		frameIncr = 0.0f;
	}
	if (timer < 25.0f)
	{
		self->enemy.x += 1;
	}
	else if (timer >= 25.0f)
	{
		self->enemy.x -= 1;

	}
	if (timer >= 50.0f)
	{
		timer = 0.0f;
	}
	self->frame = (int)frameIncr;
	entity_update(self);
	
	self->frame = self->frame + 0.1;
	vector2d_add(self->position, self->position, self->velocity);
	if (self->frame > 4)self->frame = 0;
	entity_update(self);
}

void patroller_free(Entity *self)
{
	if (!self)return;
	gf2d_sprite_free(self);
	free(self);
}

void patroller_draw(Entity *self)
{
	if (!self)return;
	//gf2d_rect_draw(self->enemy, gfc_color(0, 10, 0, 1), vector2d(0, 0));
}