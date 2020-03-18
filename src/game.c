#include <SDL.h>
#include "gf2d_graphics.h"
#include "gf2d_sprite.h"
#include "simple_logger.h"
#include "gfc_color.h"
#include "player.h"
#include "gfc_vector.h"
#include "entity.h"
#include "level.h"
#include "interactables.h"
#include "patroller.h"
#include "projectile.h"
#include "hunter.h"
#include "health_bar.h"
#include <stdio.h>



int main(int argc, char * argv[])
{
	/*variable declarations*/
	int done = 0;
	int posX = 20;
	int posY = 30;
	const Uint8 * keys;
	Sprite *sprite;
	SDL_Window *window=NULL;
	SDL_Surface *surface=NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Texture *texture=NULL;
	if (surface = NULL)slog("fuck");
	SDL_Init(SDL_INIT_VIDEO);
	//Shape bounds;
	int mx, my;
	float mf = 0;
	Sprite *mouse;
	Vector4D mouseColor = { 255, 100, 255, 200 };
	SDL_Rect bounds = { 0, 0, 100, 200 };
	Level *level;
	Entity *bug;
	Entity *player;
	Entity *rock;
	Entity *water;
	Entity *patroller;
	Entity *shot;
	Entity *hunter;
	Entity *lava;

	/*program initializtion*/
	init_logger("gf2d.log");
	slog("---==== BEGIN ====---");
	gf2d_graphics_initialize(
		"gf2d",
		1200,
		720,
		1200,
		720,
		vector4d(0, 0, 0, 255),
		0);
	gf2d_graphics_set_frame_delay(16);
	gf2d_sprite_init(1024);
	SDL_ShowCursor(SDL_DISABLE);
	keys = SDL_GetKeyboardState(NULL);
	entity_manager_init(1024);

	/*demo setup*/
	level = level_new("images/backgrounds/bg_flat.png", bounds);
	//bounds = gf2d_shape_rect(50, 50, 1100, 600);
	//sprite = gf2d_sprite_load_all("images/health3.png", 800, 500, 16);
	//mouse = gf2d_sprite_load_all("images/pointer.png",32,32,16);
	/*main game loop*/
	//bug = newTestEnt();
	player = new_player(vector2d(0.0, 0.0));
	rock = new_rock(vector2d(0,0));
	patroller = patroller_new(vector2d(0, 0));
	hunter = hunter_new(vector2d(0, 0));
	lava = health_new(vector2d(0, 0));
	window = SDL_CreateWindow(
		"character sheet",
		100,
		100,
		640,
		480,
		SDL_WINDOW_OPENGL
		);
	renderer = SDL_CreateRenderer(window, -1, 0);
	
	if (player->dead==true)
	{
		slog("bye bye");
	}
	surface = SDL_LoadBMP("images/health3.bmp");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	
	//shot = projectile_new(vector2d(player->position.x, player->position.y), player);
	
	vector2d_set(player->position, 100, 100);
	//vector2d_set(self->position, 50, 100);
	while (!done)
	{

		SDL_PumpEvents();   // update SDL's internal event structures
		keys = SDL_GetKeyboardState(NULL); // get the keyboard state for this frame
		/*update things here*/
		SDL_GetMouseState(&mx, &my);
		mf += 0.1;
		if (mf >= 16.0)mf = 0;
		entity_update_all();

		gf2d_graphics_clear_screen();// clears drawing buffers
		// all drawing should happen betweem clear_screen and next_frame
		//backgrounds drawn first
		gf2d_sprite_draw_image(sprite, vector2d(0, 0));
		//gf2d_shape_draw(level->bounds, gfc_color(0, 10, 0, 1), vector2d(0, 0));
		gf2d_rect_draw(level->bounds, gfc_color(0, 10, 0, 1), vector2d(0, 0));
		//vector2d_set(self->position, 50, 50);
		level_draw(level);
		//rock_draw(rock);
		rock_draw(water);
		rock_draw(lava);
		projectile_draw(shot);
		patroller_draw(patroller);
		//hunter_draw(hunter);
		entity_draw_all();
		//UI elements last
		gf2d_sprite_draw(
			mouse,
			vector2d(mx, my),
			NULL,
			NULL,
			NULL,
			NULL,
			&mouseColor,
			(int)mf);
		entity_update(bug);
		player_update(player, level, rock, water, lava);
		rock_update(rock);
		rock_update(water);
		rock_update(lava);
		patroller_update(patroller);
		//projectile_update(shot, player);
		hunter_update(hunter, player);
		health_update(lava, player);
		SDL_Rect dstrect = { 5, 5, 320, 240 };
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		entity_update_all();
		//player_think(player, level);
		gf2d_grahics_next_frame();// render current draw frame and skip to the next frame
		if (keys[SDL_SCANCODE_ESCAPE])done = 1; // exit condition
		//slog("Rendering at %f FPS",gf2d_graphics_get_frames_per_second());
	}
	level_free(level);
	entity_free(player);
	entity_free(shot);
	player_free(player);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	slog("---==== END ====---");
	return 0;
}
/*eol@eof*/