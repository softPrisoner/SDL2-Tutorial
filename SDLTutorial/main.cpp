#include  <stdio.h>

extern "C" {
#include <SDL.h>
#include <SDL_thread.h>
};

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("SDL Surface View", 200, 200, 800, 600, SDL_WINDOW_SHOWN);

	SDL_Rect rect;
	rect.x = 100;
	rect.y = 100;

	SDL_Surface* surface = SDL_GetWindowSurface(window);

	SDL_Surface* image = SDL_LoadBMP("sample.bmp");

	SDL_BlitSurface(image, NULL, surface, &rect);

	SDL_UpdateWindowSurface(window);
	SDL_Delay(3000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}