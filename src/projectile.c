#include "projectile.h"
#include "simple_logger.h"
#include "entity.h"
#include "player.h"

Entity *projectile_new(Vector2D position, Entity *player)
{
	Entity *self;
	self = entity_new();
	if (!self)return NULL;
	self->box = gf2d_rect(player->position.x + 50, player->position.y, 20, 20);
	slog("shooting");
	//self->update = projectile_update(self, player);
	return self;
}

void projectile_update(Entity *self, Entity *player)
{
	gf2d_rect_draw(self->box, gfc_color(0, 10, 10, 1));
	self->velocity = vector2d(1, 0);
	slog("projectile update");
}

void projectile_free(Entity *self);

void projectile_draw(Entity *self)
{

}