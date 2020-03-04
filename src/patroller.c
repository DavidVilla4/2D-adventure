#include "patroller.h"
#include "simple_logger.h"

Entity *self;
static float timer = 0.0f;
Entity *patroller_new(Vector2D position)
{
	self = entity_new();

	if (!self)
	{
		slog("no ent created");
		return NULL;
	}
	float posX = 100;
	float posY = 100;
	self->enemy=gf2d_rect(100, 100, 50, 50);
	return self;
}

void patroller_update(Entity *self)
{
	int distance;
	timer += 0.1f;
	gf2d_rect_draw(self->enemy, gfc_color(0, 0, 10, 1), vector2d(0, 0));
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

	/*
	for (distance = 0; distance <= 10; distance+=1)
	{
		if (distance < 10)
		{
			slog("distance %d", distance);
		}
		if (distance == 10)
		{
			slog("distance reached");
			break;
		}
		
	}
	
	
	if (self->enemy.x >= 120)
	{
		self->enemy.x -= 10;
	}
	*/
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
	gf2d_rect_draw(self->rock, gfc_color(10, 0, 0, 1), vector2d(0, 0));
}