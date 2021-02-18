#include "game_of_life.h"
#include <time.h>

int main(int argc, char *argv[])
{
	srand(time(NULL));
	// Initializations
	static int *generation = NULL;
	static int *generation_old = NULL;
	static uint32_t frame_start, frame_time;
	SDL_Event e;
	SDL_Window *window = NULL;
	SDL_Renderer *screen_renderer = NULL;
	// Start Screen
	size_t size = ((WIDTH+2) * (HEIGHT+2));
	// Define and allocate size of virtual world
	generation = (int*)malloc(size * sizeof(*generation));
	generation_old = (int*)malloc(size * sizeof(*generation_old));
	memset(generation,0,size*sizeof(*generation));
	memset(generation_old,0,size*sizeof(*generation_old));
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL couldn't initialize! SDL_Error: %s \n", SDL_GetError());
		SDL_Quit();
		return 0;
	}
	window = SDL_CreateWindow("Cellular Automata",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			WIDTH,
			HEIGHT,
			SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		printf("Window couldn't be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 0;
	}
	screen_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(screen_renderer == NULL)
	{
		printf("Couldn't create renderer! SDL_Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 0;
	}
	// Stop condition flag
	int condition = 0;
	// Create lifeforms!
	
	create_glider(generation, HEIGHT/2,WIDTH/2);

	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	blinker(generation, 1+rand()%WIDTH,1+rand()%HEIGHT);
	create_glider(generation, 1+HEIGHT/2,WIDTH/2);
	create_glider(generation, 2+HEIGHT/2,WIDTH/2);
	create_glider(generation, 3+HEIGHT/2,WIDTH/2);
	create_glider(generation, 4+HEIGHT/2,WIDTH/2);
	create_glider(generation, 5+HEIGHT/2,WIDTH/2);
	create_glider(generation, 6+HEIGHT/2,WIDTH/2);
	create_glider(generation, 7+HEIGHT/2,WIDTH/2);
	create_glider(generation, 8+HEIGHT/2,WIDTH/2);
	create_glider(generation, 9+HEIGHT/2,WIDTH/2);
	create_glider(generation, 10+HEIGHT/2,WIDTH/2);
	create_glider(generation, 11+HEIGHT/2,WIDTH/2);
	create_glider(generation, 12+HEIGHT/2,WIDTH/2);
	create_glider(generation, 13+HEIGHT/2,WIDTH/2);
	create_glider(generation, 14+HEIGHT/2,WIDTH/2);
	create_glider(generation, 1+HEIGHT/2,WIDTH/2+1);
	create_glider(generation, 1+HEIGHT/2,WIDTH/2+2);
	create_glider(generation, 1+HEIGHT/2,WIDTH/2+3);
	create_glider(generation, 14+HEIGHT/2,WIDTH/2);
	create_glider(generation, 12+HEIGHT/2,WIDTH/2);
	blinker(generation,300,200);
	blinker(generation,200,100);
	blinker(generation,405,300);
	while(!condition)
	{
		// Start fps timer
		frame_start = SDL_GetTicks();
		//Handle events
		condition = handle_events(&e,condition);
		// Calculate changes on world
		update_generation(generation,generation_old);
		// Update Screen
		render_generation(generation, screen_renderer);
		// Finish frame calc
		frame_time = SDL_GetTicks() - frame_start;
		if(FRAME_DELAY > frame_time)
		{
			SDL_Delay((int) (FRAME_DELAY - frame_time));
		}
	}

	free(generation);
	free(generation_old);
	SDL_DestroyRenderer(screen_renderer);
	screen_renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
	return 0;
}
