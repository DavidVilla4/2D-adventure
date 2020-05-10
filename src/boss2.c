#include "boss2.h"
#include "player.h"

static float timer = 0.0f;

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
	self->sprite = gf2d_sprite_load_all("images/terrex.png", 95,80,3);
	//gf2d_sprite_draw_image(self->sprite, vector2d(350, 400));
	self->box = gf2d_rect(500, 600, 30, 50);

	self->hitbox = gf2d_rect(self->position.x, self->position.y, 20, 20);

	

	return self;
}

void boss2_update(Entity *self, Entity *player)
{
	//gf2d_sprite_draw_image(self->sprite, vector2d(self->box.x, self->box.y));

	gf2d_rect_draw(self->box, gfc_color(1, 0, 0, 1));

	self->box.x = self->position.x+30;
	self->box.y = self->position.y+20;
	self->box.x += 10;
	timer += 0.1;
	
	/*
	if (collide_rect(self->box, player->sword))
	{
		gf2d_rect_draw(self->hitbox, gfc_color(1, 0, 0, 1));
		
		self->hitbox.x += 1;
	}
	else
	{
		vector2d_set(self->hitbox, 700, 300);
	}*/
	if (player->position.x+100 - self->box.x<0)//less that if creature is to the right of player
	{
		//self->velocity.x -= .03;
		self->box.x -= 1;
	}
	else
	{
		//self->velocity.x += .03;
		self->box.x += 1;
	}
	if (player->position.y + 50 - self->box.y < 0)
	{
		self->box.y -= 1;
	}
	else
	{
		self->box.y += 1;
	}

}

void boss2_free(Entity *self);

void boss2_draw(Entity *self);