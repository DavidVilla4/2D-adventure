#include "sign.h"

Entity *sign_new(Vector2D poisiton)
{
	Entity *self;
	self = entity_new();

	if (!self)
	{
		slog("no ent created");
		return NULL;
	}

	//self->sprite = gf2d_sprite_load_image("images/signpost1.png");
	self->position.x = 700;
	self->position.y = 300;

	self->hitbox = gf2d_rect(100, self->position.y, 30, 50);

	//self->new_sprite = gf2d_sprite_load_image("images/po.png");
	return self;
}

void sign_update(Entity *self, Entity *player)
{
	//gf2d_rect_draw(self->hitbox, gfc_color(1, 0, 1, 1));

	
}

void sign_free(Entity *self);

void boss1_draw(Entity *self);