#include "gfc_vector.h"
#include "entity.h"
#include "gf2d_sprite.h"
#include "simple_logger.h"
#include "gf2d_shape.h"
#include "gfc_color.h"
#include "collision.h"
#include "player.h"
#include "level.h"



Entity *self;
Entity *combat;
Level *level;

void player_think(Entity *self);

Entity *new_player(Vector2D position)
{

	self = entity_new();
	
	if (!self)
	{
		slog("no ent created");
		return NULL;
	}
	self->sprite = gf2d_sprite_load_all(
		"images/space_bug.png",
		128,
		128,
		16);
	//self->position = *player_set_position(0, 0);
	///self->hitbox = gf2d_rect(position.x, position.y, 20, 35);
	self->box = gf2d_shape_rect(1100, 100, 50, 25);
	//self->hitbox = gf2d_rect(1100, 100, 50, 25);
	//gf2d_draw_rect(self->pbox, vector4d(0, 0, 10, 1));
	
	return self;

}


void player_update(Entity *self)
{
	const Uint8 *keys;
	keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_A])
	{
		self->position.x -= 3;
		if (keys[SDL_SCANCODE_P])
		{
			self->sword = gf2d_shape_rect(self->position.x, self->position.y, 60, 20);
			gf2d_shape_draw(self->sword, gfc_color(0, 0, 10, 1), vector2d(-25, 50));
			self->sword.s.c.x = self->position.x + 5000;
			self->sword.s.c.y = self->position.y + 50;
		}
	}
	if (keys[SDL_SCANCODE_D])
	{
		self->position.x += 3;
		if (keys[SDL_SCANCODE_P])
		{
			self->sword = gf2d_shape_rect(self->position.x, self->position.y, 60, 20);
			gf2d_shape_draw(self->sword, gfc_color(0, 0, 10, 1), vector2d(80, 50));
			self->sword.s.c.x = self->position.x + 5000;
			self->sword.s.c.y = self->position.y + 50;
		}
	}
	if (keys[SDL_SCANCODE_W])
	{
		self->position.y -= 3;
		if (keys[SDL_SCANCODE_P])
		{
			self->position.y += 3;
			self->sword = gf2d_shape_rect(self->position.x, self->position.y, 20, 60);
			gf2d_shape_draw(self->sword, gfc_color(0, 0, 10, 1), vector2d(50, -10));
			self->sword.s.c.x = self->position.x + 5000;
			self->sword.s.c.y = self->position.y + 50;
		}
		
		
	}
	if (keys[SDL_SCANCODE_S])
	{
		self->position.y += 3;
		if (keys[SDL_SCANCODE_P])
		{
			self->position.y -= 3;
			self->sword = gf2d_shape_rect(self->position.x, self->position.y, 20, 60);
			gf2d_shape_draw(self->sword, gfc_color(0, 0, 10, 1), vector2d(50, 75));
			self->sword.s.c.x = self->position.x + 5000;
			self->sword.s.c.y = self->position.y + 50;
		}
	}
	entity_update(self);
	
	gf2d_shape_draw(self->box, gfc_color(0, 10, 0, 1), vector2d(0,0));
	//gf2d_shape_draw(self->*testbox, gfc_color(10, 0, 0, 1), vector2d(0, 0));
	//gf2d_rect_draw(self->hitbox, gfc_color(0, 0, 10, 1));
	//gf2d_draw_circle(self->position, self->radius, vector4d(255, 0, 255, 255));
	self->box.s.c.x = self->position.x + 30;
	self->box.s.c.y = self->position.y + 50;
	self->think = player_think;
	

}

void player_think(Entity *self, Level *level)
{
	
	if (!self)
	{
		slog("no player given");
		return NULL;
	}
	/*
	//slog("");
	if (collide_rect(level->bounds, self->box))
	{
		slog("collided");
		return;
	}
	
	if (gf2d_shape_overlap(self->box, level->bounds))
	{
		slog("collided");
		return;
	}*/
}


