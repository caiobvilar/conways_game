#ifndef _GAMEOFLIFE_H_
#define _GAMEOFLIFE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#define WIDTH 300
#define HEIGHT 300

#define FPS 60
#define FRAME_DELAY 1000/FPS

void update_generation(int *generation, int *old_generation);
void render_generation(int *generation, SDL_Renderer *renderer);
int check_neighbors(int *generation, int x, int y);
int handle_events(SDL_Event *event, int condition);
void create_glider(int *generation, int x, int y);
void still_dot(int *generation, int x, int y);
void blinker(int *generation, int x, int y);
void glider_gun(int *generation, int x,int y);
#endif /* _GAMEOFLIFE_H_*/
