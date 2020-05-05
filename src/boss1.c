#include "boss1.h"
#include "gf2d_sprite.h"
#include "simple_logger.h"

static float timer = 0.0f;
static float new_timer = 0.0f;
Entity *boss1_new(Vector2D poisiton)
{
	Entity *self;
	self = entity_new();

	if (!self)
	{
		slog("no ent created");
		return NULL;
	}
	
	//self->sprite = gf2d_sprite_load_image("images/po.png");

	self->box = gf2d_rect(600, 325, 232, 217);

	self->hitbox = gf2d_rect(570, 325, 50, 25);

	self->lava = gf2d_rect(570, 425, 50, 25);
	
	self->bounce = gf2d_rect(570, 525, 50, 25);

	self->ladder = gf2d_rect(570, 470, 50, 25);

	self->enemy = gf2d_rect(570, 370, 50, 25);

	return self;
}

void boss1_update(Entity *self)
{
	gf2d_rect_draw(self->box, gfc_color(1, 0, 0, 1));
	gf2d_rect_draw(self->hitbox, gfc_color(0, 0, 1, 1));
	gf2d_rect_draw(self->lava, gfc_color(0, 0, 1, 1));
	gf2d_rect_draw(self->bounce, gfc_color(0,0,1,1));
	gf2d_rect_draw(self->ladder, gfc_color(0, 0, 1, 1));
	gf2d_rect_draw(self->enemy, gfc_color(0, 0, 1, 1));
	//gf2d_sprite_draw_image(self->sprite, vector2d(800,300));
	timer += 0.1f;
	new_timer += 0.1f;

	if (timer < 25.0f)
	{
		self->hitbox.x -= 1;
		self->hitbox.y -= 1;
		self->lava.x -= 1;
		self->bounce.x -= 1;
		self->bounce.y += 1;

		
	}
	else if (timer >= 25.0f)
	{
		vector2d_set(self->hitbox, 570, 325);
		vector2d_set(self->lava, 570, 425);
		vector2d_set(self->bounce, 570, 525);
		timer = 0.0f;
	}

	if (new_timer < 15.0f)
	{
		self->ladder.x -= 1;
		self->ladder.y -= 0.5;
		self->enemy.x -= 1;
		self->enemy.y += 0.5;
	}
	else if (new_timer >= 15.0f)
	{
		vector2d_set(self->ladder, 570, 475);
		vector2d_set(self->enemy, 570, 375);
		new_timer = 0.0f;
	}
}

void boss1_free(Entity *self);

void boss1_draw(Entity *self)
{

}