#include "enemy.h"
#include "simple_logger.h"

static float timer = 0.0f;
Entity *enemy_new(Vector2D position)
{
	Entity *self;
	self = entity_new();
	if (!self)return NULL;
	self->enemy = gf2d_rect(300, 400, 40, 50);

	return self;
}

void enemy_update(Entity *self)
{
	gf2d_rect_draw(self->enemy, gfc_color(1, 3, 1, 1), vector2d(0, 0));
	timer += 0.1f;
	if (timer < 25.0f)
	{
		self->enemy.x += 1;
	}
	else if (timer >= 25.0f&&timer<50.0f)
	{
		self->enemy.y -= 1;

	}
	else if (timer >= 50.0f&&timer < 75.0f)
	{
		self->enemy.x -= 1;
	}
	else if (timer >= 75.0f&&timer < 100.0f)
	{
		self->enemy.y += 1;
	}
	if (timer >= 100.0f)
	{
		timer = 0.0f;
	}

	entity_update(self);
}

void enemy_free(Entity *self)
{
	if (!self)return;
	gf2d_sprite_free(self);
	free(self);
}

void enemy_draw(Entity *self)
{
	if (!self)return;
	gf2d_rect_draw(self->enemy, gfc_color(1, 3, 1, 1), vector2d(0, 0));
}