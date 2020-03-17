#include "projectile.h"
#include "simple_logger.h"
#include "entity.h"
#include "player.h"

Entity *projectile_new(Vector2D position, Entity *player)
{
	Entity *self;
	self = entity_new();
	if (!self)return NULL;
	self->box = gf2d_rect(player->position.x+100, player->position.y, 20, 20);
	gf2d_rect_draw(self->box, gfc_color(0, 10, 10, 1));
	self->box.x += 1;
	self->update = projectile_update;
	return self;
}

void projectile_update(Entity *self, Entity *player)
{
	gf2d_rect_draw(self->box, gfc_color(0, 10, 10, 1));
	self->box.x += 1;
	slog("projectile update");
	entity_update(self);
}

void projectile_free(Entity *self)
{
	if (!self)return;
	gf2d_sprite_free(self);
	free(self);
}

void projectile_draw(Entity *self)
{
	if (!self)return;
	gf2d_rect_draw(self->box, gfc_color(0, 10, 10, 1));
}