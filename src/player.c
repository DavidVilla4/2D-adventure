#include "gfc_vector.h"
#include "entity.h"
#include "gf2d_sprite.h"
#include "simple_logger.h"
#include "gfc_types.h"
#include "gf2d_shape.h"
#include "gfc_color.h"
#include "collision.h"
#include "player.h"
#include "level.h"
#include "interactables.h"



Entity *self;
Entity *combat;
Level *level;
Rect *hitbox;
Entity rock;

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

	self->box = gf2d_rect(self->position.x, self->position.y, 50, 25);
	vector2d(self->velocity.x, self->velocity.y);
	
	return self;

}


void player_update(Entity *self, Level *level, Entity *rock, Entity *water)
{
	vector2d_add(self->position, self->position, self->velocity);

	const Uint8 *keys;
	keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_A])
	{
		self->velocity = vector2d(-3, 0);
		
		if (keys[SDL_SCANCODE_P])
		{
			//self->position.x += 3;
			self->velocity = vector2d(0, 0);
			self->sword = gf2d_rect(self->position.x-30, self->position.y+50, 60, 20);
			gf2d_rect_draw(self->sword, gfc_color(0, 0, 10, 1));	
			
		}
	}
	else if (keys[SDL_SCANCODE_D])
	{
		self->velocity = vector2d(3,0);
		if (collide_rect(water->water, self->box))//water code
		{
			slog("slide");
			self->velocity = vector2d(0, 3);
		}
		
		if (keys[SDL_SCANCODE_P])
		{
			self->velocity = vector2d(0, 0);
			self->sword = gf2d_rect(self->position.x+80, self->position.y+50, 60, 20);
			gf2d_rect_draw(self->sword, gfc_color(0, 0, 10, 1));
		}
	}
	else if (keys[SDL_SCANCODE_W])
	{
		self->velocity = vector2d(0, -3);
		
		if (keys[SDL_SCANCODE_P])
		{
			self->velocity = vector2d(0, 0);
			self->sword = gf2d_rect(self->position.x+45, self->position.y-10, 20, 60);
			gf2d_rect_draw(self->sword, gfc_color(0, 0, 10, 1));
		}
		
		
	}
	


	else if (keys[SDL_SCANCODE_S])
	{
		self->velocity=vector2d(0,3);
		//self->position.y += 3;
		if (keys[SDL_SCANCODE_P])
		{
			self->velocity = vector2d(0, 0);
			self->sword = gf2d_rect(self->position.x+45, self->position.y+75, 20, 60);
			gf2d_rect_draw(self->sword, gfc_color(0, 0, 10, 1), vector2d(50,75));
			
		}
	}
	else
	{
		self->velocity = vector2d(0, 0);
	}


	if (collide_predict(rock->rock, self->box))
	{
		if (keys[SDL_SCANCODE_W])
		{
			self->velocity = vector2d(0, .03);
			rock->rock.y -= 20;
		}
		if (keys[SDL_SCANCODE_S])
		{

			self->velocity = vector2d(0, -0.03);
		}
	}
	if (collide_rect(rock->rock, self->box))
	{
		if (keys[SDL_SCANCODE_D])
		{
			self->velocity = vector2d(-0.03-5, 0);
		}
		if (keys[SDL_SCANCODE_A])
		{

			self->velocity = vector2d(0.03+5, 0);
		}
	}
	
	if (collide_predict(water->water, self->box))//water code
	{
		self->velocity=vector2d(0,3);
	}
	
	entity_update(self);
	

	gf2d_rect_draw(self->box, gfc_color(0, 10, 0, 1), vector2d(0, 0));
	self->box.x = self->position.x + 30;
	self->box.y = self->position.y + 50;
	self->think = player_think;
	


}

void player_think(Entity *self, Level *level)
{
	
	if (!self)
	{
		slog("no player given");
		return NULL;
	}
	
	
	
	
	
}


