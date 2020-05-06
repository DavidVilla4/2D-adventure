#include "boss2.h"
#include "player.h"
Entity *boss2_new(Vector2D poisiton)
{
	Entity *self;
	self = entity_new();

	if (!self)
	{
		slog("no ent created");
		return NULL;
	}
	self->position.x = 700;
	self->position.y = 300;
	self->sprite = gf2d_sprite_load_all("images/terrex.png", 90,64,4);
	//gf2d_sprite_draw_image(self->sprite, vector2d(350, 400));
	self->box = gf2d_rect(500, 600, 50, 25);

	self->hitbox = gf2d_rect(self->position.x, self->position.y, 20, 20);

	return self;
}

void boss2_update(Entity *self, Entity *player)
{
	gf2d_sprite_draw_image(self->sprite, vector2d(self->box.x, self->box.y));

	gf2d_rect_draw(self->box, gfc_color(1, 0, 0, 1));

	self->box.x = self->position.x;
	self->box.y = self->position.y;

	if (collide_rect(self->box, player->sword))
	{
		gf2d_rect_draw(self->hitbox, gfc_color(1, 0, 0, 1));
		
		self->hitbox.x += 1;
	}
	else
	{
		vector2d_set(self->hitbox, 700, 300);
	}
}

void boss2_free(Entity *self);

void boss2_draw(Entity *self);