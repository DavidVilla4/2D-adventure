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
#include "enemy.h"
#include "heart.h"
#include "proj_left.h"
#include "boss1.h"
#include "stone.h"
#include "gfc_audio.h"
#include <stdio.h>

#define MAX_SHOTS 10	


int main(int argc, char * argv[])
{
	/*variable declarations*/
	int done = 0;
	int posX = 20;
	int posY = 30;
	const Uint8 * keys;
	Sprite *sprite;
	Sprite *blue;
	SDL_Window *window=NULL;
	SDL_Surface *surface=NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Texture *texture=NULL;
	if (surface = NULL)slog("fuck");
	SDL_Init(SDL_INIT_VIDEO);
	Entity *shots[MAX_SHOTS] = { NULL };
	//Shape bounds;
	int mx, my;
	float mf = 0;
	static float timer = 0.0f;
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
	Entity *shot2;
	Entity *hunter;
	Entity *lava;
	Entity *bounce;
	Entity *enemy;
	Entity *heart;
	Sound *menu_music;
	//

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
	gfc_audio_init(256, 16, 4, 1, 1, 1);
	gf2d_sprite_init(1024);
	SDL_ShowCursor(SDL_DISABLE);
	keys = SDL_GetKeyboardState(NULL);
	entity_manager_init(1024);
	
	/*demo setup*/
	level = level_new("images/backgrounds/2dbg.png", bounds);
	sprite = gf2d_sprite_load_image("images/backgrounds/2dbg.png");
	//bounds = gf2d_shape_rect(50, 50, 1100, 600);
	//sprite = gf2d_sprite_load_all("images/water1.png", 100, 150, 16);
	//blue = gf2d_sprite_load_all("images/water1.png", 800, 500, 16);
	
	//mouse = gf2d_sprite_load_all("images/pointer.png",32,32,16);
	/*main game loop*/
	//bug = newTestEnt();
	player = new_player(vector2d(0.0, 0.0));
	rock = new_rock(vector2d(0,0));
	patroller = patroller_new(vector2d(0, 0));
	hunter = hunter_new(vector2d(0, 0));
	lava = health_new(vector2d(0, 0));
	enemy = enemy_new(vector2d(0, 0));
	heart = heart_new(vector2d(0, 0));
	//shot = projectile_new(vector2d(0, 0), player);
	//menu_music=gfc_sound_load("music/the_field_of_dreams.mp3",3,-1);
	
	
	window = SDL_CreateWindow(
		"character sheet",
		100,
		100,
		640,
		480,
		SDL_WINDOW_OPENGL
		);
	renderer = SDL_CreateRenderer(window, -1, 0);
	
	
	surface = SDL_LoadBMP("images/new_health.bmp");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	

	
	vector2d_set(player->position, 100, 100);
	vector2d_set(shot->position, player->position.x, player->position.y);
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
		
		//gfc_sound_play(menu_music, 0, 3, -1, -1);
	
		gf2d_sprite_draw_image(sprite, vector2d(100, 80));
		//gf2d_shape_draw(level->bounds, gfc_color(0, 10, 0, 1), vector2d(0, 0));
		gf2d_rect_draw(level->bounds, gfc_color(0, 10, 0, 1), vector2d(0, 0));

		if (keys[SDL_SCANCODE_O])
		{
		shot = projectile_new(vector2d(0, 0), player);
		}
		//vector2d_set(self->position, 50, 50);
		level_draw(level);
		//rock_draw(rock);
		rock_draw(water);
		rock_draw(lava);
		//projectile_draw(shot);
		patroller_draw(patroller);
		enemy_draw(enemy);
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
		rock_update(bounce);
		rock_update(heart);
		enemy_update(enemy);
		heart_update(heart, player);
		patroller_update(patroller);
		projectile_update(shot, player);
		hunter_update(hunter, player);
		health_update(lava, player);
		SDL_Rect dstrect = { 5, 5, 320, 240 };
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		entity_update_all();
		if (keys[SDL_SCANCODE_0])
		{
			done = 1;
			Boss1();
		}
		
		//player_think(player, level);
		gf2d_grahics_next_frame();// render current draw frame and skip to the next frame
		if (keys[SDL_SCANCODE_ESCAPE])
		{
			menu();
			done = 1;
		}
			// exit condition
		//slog("Rendering at %f FPS",gf2d_graphics_get_frames_per_second());
	}
	//gfc_sound_free(menu_music);
	
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

int menu()
{
	/*variable declarations*/
	int done = 0;
	int posX = 20;
	int posY = 30;
	const Uint8 * keys;
	Sprite *sprite;

	SDL_Init(SDL_INIT_VIDEO);
	//Shape bounds;
	int mx, my;
	float mf = 0;
	Sprite *mouse;
	Sprite *option;
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
	Entity *bounce;
	Entity *enemy;
	Entity *heart;

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
	//level = level_new("images/backgrounds/bg_flat.png", bounds);
	//bounds = gf2d_shape_rect(50, 50, 1100, 600);
	sprite = gf2d_sprite_load_all("images/banners/play_image.png", 300, 80, 16);
	option = gf2d_sprite_load_all("images/banners/options.png", 300, 80, 16);
	//mouse = gf2d_sprite_load_all("images/pointer.png",32,32,16);
	/*main game loop*/
	//bug = newTestEnt();

	player = new_player(vector2d(0.0, 0.0));
	//rock = new_rock(vector2d(0, 0));
	patroller = patroller_new(vector2d(0, 0));
	hunter = sel_new(vector2d(0, 0));
	lava = health_new(vector2d(0, 0));
	enemy = enemy_new(vector2d(0, 0));
	heart = heart_new(vector2d(0, 0));

	

	//shot = projectile_new(vector2d(player->position.x, player->position.y), player);

	//vector2d_set(player->position, 100, 100);
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
		gf2d_sprite_draw_image(sprite, vector2d(400, 200));
		gf2d_sprite_draw_image(option, vector2d(400, 400));

		projectile_draw(shot);
		
		sel_update(hunter);
		
		entity_update_all();
		
		
		
		//player_think(player, level);
		gf2d_grahics_next_frame();// render current draw frame and skip to the next frame
		if (keys[SDL_SCANCODE_ESCAPE])done = 1; // exit condition
		//slog("Rendering at %f FPS",gf2d_graphics_get_frames_per_second());
	}


	slog("---==== END ====---");
	return 0;
}

int Level2()
{
	/*variable declarations*/
	int done = 0;
	int posX = 20;
	int posY = 30;
	const Uint8 * keys;
	Sprite *sprite;
	Sprite *blue;
	
	Entity *shots[MAX_SHOTS] = { NULL };
	//Shape bounds;
	int mx, my;
	float mf = 0;
	static float timer = 0.0f;
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
	Entity *shot2;
	Entity *hunter;
	Entity *lava;
	Entity *bounce;
	Entity *enemy;
	Entity *heart;
	Sound *menu_music;
	//

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
	gfc_audio_init(256, 16, 4, 1, 1, 1);
	gf2d_sprite_init(1024);
	SDL_ShowCursor(SDL_DISABLE);
	keys = SDL_GetKeyboardState(NULL);
	entity_manager_init(1024);

	/*demo setup*/
	level = level_new("images/backgrounds/2dbg.png", bounds);
	sprite = gf2d_sprite_load_image("images/backgrounds/2dbg.png");
	//bounds = gf2d_shape_rect(50, 50, 1100, 600);
	//sprite = gf2d_sprite_load_all("images/water1.png", 100, 150, 16);
	//blue = gf2d_sprite_load_all("images/water1.png", 800, 500, 16);

	//mouse = gf2d_sprite_load_all("images/pointer.png",32,32,16);
	/*main game loop*/
	//bug = newTestEnt();
	player = new_player(vector2d(0.0, 0.0));
	rock = new_rock(vector2d(0, 0));
	patroller = patroller_new(vector2d(0, 0));
	hunter = hunter_new(vector2d(0, 0));
	lava = health_new(vector2d(0, 0));
	enemy = enemy_new(vector2d(0, 0));
	heart = heart_new(vector2d(0, 0));
	//shot = projectile_new(vector2d(0, 0), player);
	//menu_music=gfc_sound_load("music/the_field_of_dreams.mp3",3,-1);





	vector2d_set(player->position, 100, 100);
	vector2d_set(shot->position, player->position.x, player->position.y);
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

		//gfc_sound_play(menu_music, 0, 3, -1, -1);

		gf2d_sprite_draw_image(sprite, vector2d(100, 80));
		//gf2d_shape_draw(level->bounds, gfc_color(0, 10, 0, 1), vector2d(0, 0));
		gf2d_rect_draw(level->bounds, gfc_color(0, 10, 0, 1), vector2d(0, 0));

		/*if (keys[SDL_SCANCODE_O])
		{
		shot = projectile_new(vector2d(0, 0), player);
		}*/
		//vector2d_set(self->position, 50, 50);
		level_draw(level);
		//rock_draw(rock);
		rock_draw(water);
		rock_draw(lava);
		//projectile_draw(shot);
		patroller_draw(patroller);
		enemy_draw(enemy);
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
		rock_update(bounce);
		rock_update(heart);
		enemy_update(enemy);
		heart_update(heart, player);
		patroller_update(patroller);
		projectile_update(shot, player);
		hunter_update(hunter, player);
		health_update(lava, player);
		
		entity_update_all();
		if (keys[SDL_SCANCODE_0])
		{
			done = 1;
		}

		//player_think(player, level);
		gf2d_grahics_next_frame();// render current draw frame and skip to the next frame
		if (keys[SDL_SCANCODE_ESCAPE])
		{
			menu();
			done = 1;
		}
		// exit condition
		//slog("Rendering at %f FPS",gf2d_graphics_get_frames_per_second());
	}
	//gfc_sound_free(menu_music);

	level_free(level);
	entity_free(player);
	entity_free(shot);
	player_free(player);

	SDL_Quit();

	slog("---==== END ====---");


	return 0;
}


int Boss1()
{
	/*variable declarations*/
	int done = 0;
	int posX = 20;
	int posY = 30;
	const Uint8 * keys;
	Sprite *sprite;
	Sprite *background;
	Sprite *stone1;
	Sprite *stone2;
	Sprite *stone3;
	Sprite *stone4;
	SDL_Window *window = NULL;
	SDL_Surface *surface = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Texture *texture = NULL;
	if (surface = NULL)slog("fuck");
	SDL_Init(SDL_INIT_VIDEO);
	//Shape bounds;
	int mx, my;
	float mf = 0;
	Sprite *mouse;
	Vector4D mouseColor = { 255, 100, 255, 200 };
	SDL_Rect bounds = { 0, 0, 100, 200 };
	Rect box1;
	Level *level;
	Entity *bug;
	Entity *player;
	Entity *rock;
	Entity *water;
	Entity *patroller;
	Entity *shot;
	Entity *hunter;
	Entity *lava;
	Entity *bounce;
	Entity *enemy;
	Entity *heart;

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
	//level = level_new("images/backgrounds/bg_flat.png", bounds);
	//bounds = gf2d_shape_rect(50, 50, 1100, 600);
	//sprite = gf2d_sprite_load_all("images/water1.png", 100, 150, 16);
	background = gf2d_sprite_load_image("images/backgrounds/desert1.jpg");
	sprite = gf2d_sprite_load_image("images/po.png");
	stone1 = gf2d_sprite_load_all("images/rock.png",500,128,0);
	stone2 = gf2d_sprite_load_all("images/rock.png", 500, 128, 0);
	//mouse = gf2d_sprite_load_all("images/pointer.png",32,32,16);
	/*main game loop*/
	//bug = newTestEnt();
	player = new_player(vector2d(0.0, 0.0));
	rock = new_rock(vector2d(0, 0));
	//patroller = patroller_new(vector2d(0, 0));
	
	lava = health_new(vector2d(0, 0));
	enemy = boss1_new(vector2d(0, 0));
	heart = heart_new(vector2d(0, 0));
	
	box1 = gf2d_rect(400, 105,54,54);

	hunter = stone_new(vector2d(0, 0));

	//shot = projectile_new(vector2d(player->position.x, player->position.y), player);
	
	vector2d_set(player->position, 300, 100);
	
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
		gf2d_sprite_draw_image(background, vector2d(100, 75));
		//gf2d_sprite_draw_image(sprite, vector2d(600, 325));
		gf2d_sprite_draw_image(stone1, vector2d(600, 200));
		gf2d_sprite_draw_image(stone2, vector2d(600, 550));
		gf2d_rect_draw(box1, gfc_color(0, 0, 1, 1));
		if (collide_rect(box1, player->box))
		{
			boss2();
		}
		//gf2d_shape_draw(level->bounds, gfc_color(0, 10, 0, 1), vector2d(0, 0));
		//gf2d_rect_draw(level->bounds, gfc_color(0, 10, 0, 1));
		//vector2d_set(self->position, 50, 50);
		//level_draw(level);
		//rock_draw(rock);
	//	rock_draw(water);
		//rock_draw(lava);
		//projectile_draw(shot);
		//patroller_draw(patroller);
		//enemy_draw(enemy);
		//hunter_draw(hunter);
		if (keys[SDL_SCANCODE_O])
		{
			shot = projectile_new(vector2d(0, 0), player);
		}
		entity_draw_all();
		//UI elements last
		
		//entity_update(bug);
		player_update(player, level, rock, water, lava);
		health_update(lava, player);
		boss1_update(enemy, player);
		stone_update(hunter, player);
		entity_update_all();
		if (keys[SDL_SCANCODE_0])
		{
			boss2();
		}
		//player_think(player, level);
		gf2d_grahics_next_frame();// render current draw frame and skip to the next frame
		if (keys[SDL_SCANCODE_ESCAPE])done = 1; // exit condition
		//slog("Rendering at %f FPS",gf2d_graphics_get_frames_per_second());
	}
	

	slog("---==== END ====---");
	return 0;
}

int boss2()
{
	/*variable declarations*/
	int done = 0;
	int posX = 20;
	int posY = 30;
	const Uint8 * keys;
	Sprite *sprite;
	Sprite *background;
	Sprite *stone1;
	Sprite *stone2;
	Sprite *stone3;
	Sprite *stone4;
	SDL_Window *window = NULL;
	SDL_Surface *surface = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Texture *texture = NULL;
	if (surface = NULL)slog("fuck");
	SDL_Init(SDL_INIT_VIDEO);
	//Shape bounds;
	int mx, my;
	float mf = 0;
	Sprite *mouse;
	Vector4D mouseColor = { 255, 100, 255, 200 };
	SDL_Rect bounds = { 0, 0, 100, 200 };
	Rect box1;
	Level *level;
	Entity *bug;
	Entity *player;
	Entity *rock;
	Entity *water;
	Entity *patroller;
	Entity *shot;
	Entity *hunter;
	Entity *lava;
	Entity *bounce;
	Entity *enemy;
	Entity *heart;

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
	//level = level_new("images/backgrounds/bg_flat.png", bounds);
	//bounds = gf2d_shape_rect(50, 50, 1100, 600);
	//sprite = gf2d_sprite_load_all("images/water1.png", 100, 150, 16);
	background = gf2d_sprite_load_image("images/backgrounds/desert1.jpg");
	sprite = gf2d_sprite_load_all("images/gorksprite.png",32,32,4);
	stone1 = gf2d_sprite_load_all("images/rock.png", 500, 128, 0);
	stone2 = gf2d_sprite_load_all("images/rock.png", 500, 128, 0);
	//mouse = gf2d_sprite_load_all("images/pointer.png",32,32,16);
	/*main game loop*/
	//bug = newTestEnt();
	player = new_player(vector2d(0.0, 0.0));
	rock = new_rock(vector2d(0, 0));
	//patroller = patroller_new(vector2d(0, 0));

	lava = health_new(vector2d(0, 0));
	enemy = boss2_new(vector2d(0, 0));
	heart = heart_new(vector2d(0, 0));


	//hunter = stone_new(vector2d(0, 0));

	//shot = projectile_new(vector2d(player->position.x, player->position.y), player);
	//vector2d_set(enemy->position, 500, 300);
	vector2d_set(player->position, 300, 100);

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
		gf2d_sprite_draw_image(background, vector2d(100, 75));
		//gf2d_sprite_draw_image(sprite, vector2d(600, 325));
		
		//gf2d_shape_draw(level->bounds, gfc_color(0, 10, 0, 1), vector2d(0, 0));
		//gf2d_rect_draw(level->bounds, gfc_color(0, 10, 0, 1));
		//vector2d_set(self->position, 50, 50);
		//level_draw(level);
		//rock_draw(rock);
		//	rock_draw(water);
		//rock_draw(lava);
		//projectile_draw(shot);
		//patroller_draw(patroller);
		//enemy_draw(enemy);
		//hunter_draw(hunter);

		entity_draw_all();
		//UI elements last

		//entity_update(bug);
		player_update(player, level, rock, water, lava);
		//rock_update(rock);
		//rock_update(water);
		//rock_update(lava);
		//rock_update(bounce);
		//rock_update(heart);
		//enemy_update(enemy);
		//heart_update(heart, player);
		//patroller_update(patroller);
		//boss1_update(rock);
		//projectile_update(shot, player);
		//hunter_update(hunter, player);
		health_update(lava, player);
		boss2_update(enemy, player);
		//stone_update(hunter, player);
		entity_update_all();
		if (keys[SDL_SCANCODE_0])
		{
			menu();
		}
		//player_think(player, level);
		gf2d_grahics_next_frame();// render current draw frame and skip to the next frame
		if (keys[SDL_SCANCODE_ESCAPE])done = 1; // exit condition
		//slog("Rendering at %f FPS",gf2d_graphics_get_frames_per_second());
	}


	slog("---==== END ====---");
	return 0;
}

/*eol@eof*/