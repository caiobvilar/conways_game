#include "game_of_life.h"

// UPDATE
void update_generation(int *generation, int *old_generation)
{
	static int i = 0;
	static int j = 0;
	static int neighbors = 0;
	size_t size = (WIDTH+2)*(HEIGHT+2);
	// Copy new to old
	memcpy(old_generation,generation,size*sizeof(*generation));
	// Make calculation on old
	for(i = 1; i < HEIGHT-1; i++)
	{
		for(j = 1; j < WIDTH-1; j++)
		{
			neighbors = check_neighbors(old_generation,j,i);
			// Birth
			if(!*(old_generation + (i*WIDTH)+j) && (neighbors == 3))
			{
				*(generation + (i*WIDTH)+j) = 1;
			}
			// Survival
			else if(*(old_generation + (i*WIDTH)+j) && ((neighbors == 2) || (neighbors == 3)))
			{
				*(generation + (i*WIDTH)+j) = 1;
			}
			// Death Starvation
			else if(*(old_generation + (i*WIDTH)+j) && (neighbors <=1) )
			{
				*(generation + (i*WIDTH)+j) = 0;
			}
			// Death Overpopulation
			else if(*(old_generation + (i*WIDTH)+j) && (neighbors >3))
			{
				*(generation + (i*WIDTH)+j) = 0;
			}
		}
	}
}
// RENDER
void render_generation(int *generation, SDL_Renderer *renderer)
{
	int i;
	int j;
	for(i = 1; i < HEIGHT-1; i++)
	{
		for(j = 1; j < WIDTH-1; j++)
		{
			if(*(generation + (i*WIDTH)+j) == 0)
			{
				SDL_SetRenderDrawColor(renderer, 0,0,0,255); // Set Pixel Black
				SDL_RenderDrawPoint(renderer, j, i);
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 255,255,255,255); //Set Pixel White
				SDL_RenderDrawPoint(renderer, j, i);
			}
		}
	}
	SDL_RenderPresent(renderer);
}
// CHECK
int check_neighbors(int *old_generation, int x, int y)
{
	// Current position -> *(old_generation + (y*WIDTH)+x)
	int count_alive = 0;
	// Upper_left
	if(*(old_generation + ((y-1)*WIDTH)+(x-1)))
	{
		count_alive++;
	}
	// Upper_mid
	if(*(old_generation + ((y-1)*WIDTH)+(x)))
	{
		count_alive++;
	}
	// Upper_right
	if(*(old_generation + ((y-1)*WIDTH)+(x+1)))
	{
		count_alive++;
	}
	// Left
	if(*(old_generation + ((y)*WIDTH)+(x-1)))
	{
		count_alive++;
	}
	// Right
	if(*(old_generation + ((y)*WIDTH)+(x+1)))
	{
		count_alive++;
	}
	// Bottom_left
	if(*(old_generation + ((y+1)*WIDTH)+(x-1)))
	{
		count_alive++;
	}
	// Bottom
	if(*(old_generation + ((y+1)*WIDTH)+(x)))
	{
		count_alive++;
	}
	// Bottom_right
	if(*(old_generation + ((y+1)*WIDTH)+(x+1)))
	{
		count_alive++;
	}
	return count_alive;
}

void create_glider(int *generation, int x, int y)
{
	*(generation + ((y)*WIDTH)+(x+1)) = 1;
	*(generation + ((y+1)*WIDTH)+(x+2)) = 1;
	*(generation + ((y+2)*WIDTH)+(x+1)) = 1;
	*(generation + ((y+2)*WIDTH)+(x)) = 1;
	*(generation + ((y+2)*WIDTH)+(x+2)) = 1;

}

void still_dot(int *generation, int x, int y)
{
	*(generation + (y*WIDTH)+x) = 1;
}
void blinker(int *generation, int x, int y)
{
	*(generation + (y*WIDTH)+x) = 1;
	*(generation + ((y+1)*WIDTH)+x) = 1;
	*(generation + ((y+2)*WIDTH)+x) = 1;
}

int handle_events(SDL_Event *event, int condition)
{
	// Handle key events
	while(SDL_PollEvent(event) != 0)
	{
		if(event->type == SDL_QUIT)
		{
			condition = 1;
		}
		if(event->type == SDL_KEYDOWN)
		{
			if(event->key.keysym.sym == SDLK_q)
			{
				condition = 1;
			}
		}
	}
	return condition;
}
void glider_gun(int *generation, int x,int y)
{
	*(generation + ((y+0)*WIDTH)+(x+0)) = 1;
}
