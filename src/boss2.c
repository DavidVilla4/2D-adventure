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
	
	self->sprite = gf2d_sprite_load_all("images/terrex.png", 95,80,2);
	self->fire_sprite = gf2d_sprite_load_all("images/portal.png",80,80,1);
	self->position.x = 700;
	self->position.y = 300;
	self->box = gf2d_rect(self->position.x, self->position.y, 30, 50);

	//self->hitbox = gf2d_rect(self->position.x, self->position.y, 20, 20);

	

	return self;
}

void boss2_update(Entity *self, Entity *player)
{
	//gf2d_rect_draw(self->box, gfc_color(1, 0, 0, 1));
	gf2d_sprite_draw_image(self->sprite, vector2d(self->box.x+30, self->box.y));
	gf2d_sprite_draw_image(self->fire_sprite, vector2d(700, 300));

	

	
	timer += 0.1;
	
	
	if (collide_rect(self->box, player->sword))
	{
		boss2_free(self);
		self->box.x += 0;
		self->box.y += 0;
	}

	if (player->position.x+30 - self->box.x<0)//less that if creature is to the right of player
	{
		//self->velocity.x -= .03;
		self->box.x -= .7;
	}
	else
	{
		//self->velocity.x += .03;
		self->box.x += .7;
	}
	if (player->position.y + 50 - self->box.y < 0)
	{
		self->box.y -= .7;
	}
	else
	{
		self->box.y += .7;
	}
}

void boss2_free(Entity *self)
{
	if (!self)
	{
		slog("nothing to free");
		return NULL;
	}
	
	gf2d_sprite_delete(self->sprite);

	gf2d_sprite_free(self);
}

void boss2_draw(Entity *self);