#include <stdio.h>

extern "C" {
#include <SDL.h>
#include <SDL_thread.h>
#include <SDL_image.h>
}

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("SDL-Tutorial-02", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

	SDL_Surface* surface = SDL_GetWindowSurface(window);

	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;

	SDL_Surface* coin = IMG_Load("big_coin.png");

	int i;
	for (i = 0;i < 10;i++) {
		rect.x += 100;
		SDL_BlitSurface(coin, NULL, surface, &rect);
	}
	SDL_UpdateWindowSurface(window);
	SDL_Delay(3000);
	SDL_FreeSurface(coin);
	SDL_FreeSurface(surface);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}