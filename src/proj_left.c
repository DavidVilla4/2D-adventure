#include "proj_left.h"


Entity *proj_left(Vector2D position, Entity *player)
{
	Entity *self;
	self = entity_new();

	if (!self)return NULL;
	self->hitbox = gf2d_rect(player->box.x, player->box.y, 20, 20);
	//self->box = gf2d_rect(40, 40, 20, 20);
	return self;
}

void update_left(Entity *self)
{
	gf2d_rect_draw(self->hitbox, gfc_color(10, 10, 0, 1));
	self->hitbox.x -= 1;
	entity_update(self);
}