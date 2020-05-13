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

	self->hitbox = gf2d_rect(self->position.x, self->position.y, 50, 25);
	
	self->up = true;

	return self;
}

void shield_update(Entity *self, Entity *player)
{
	//gf2d_rect_draw(self->box, gfc_color(1, 0, 0, 1));
	
	if (collide_rect(self->box, player->box))
	{
		
		self->up = false;
		shield_free(self);
		//self->hitbox.x = player->box.x;
		//self->hitbox.y = player->box.y;
		
	}
	
	if (self->up == false)
	{
		gf2d_rect_draw(player->box, gfc_color(0, 0, 1, 1));
	}


	return self->up;
}

void shield_free(Entity *self)
{
	if (!self)
	{
		slog("nothing to free");
		return NULL;
	}

	gf2d_sprite_delete(self->sprite);

	gf2d_sprite_free(self);
}

void shield_draw(Entity *self);