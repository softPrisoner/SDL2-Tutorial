#include <stdio.h>
extern "C" {
#include <SDL.h>
}
//define marco
#define WINDOW_INIT_POSITION 200
#define WINDOW_HEIGHT 700
#define WINDOW_WIDTH 800
SDL_Rect rect;
bool moveRight = true;
bool moveDown = true;
void updatePosition() {
	if (moveRight) {
		rect.x++;
		if (rect.x + rect.w >= WINDOW_WIDTH) {
			moveRight = false;
		}
	}
	else {
		rect.x--;
		if (rect.x <= 0) {
			moveRight = true;
		}
	}
	if (moveDown) {
		rect.y++;
		if (rect.y + rect.h >= WINDOW_HEIGHT) {
			moveDown = false;
		}
	}
	else {
		rect.y--;
		if (rect.y <= 0) {
			moveDown = true;
		}
	}
}
int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("SDL-Tutorial-04", WINDOW_INIT_POSITION, WINDOW_INIT_POSITION, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderClear(render);
	SDL_Surface* surface = SDL_GetWindowSurface(window);
	SDL_Surface* cat_surface = SDL_LoadBMP("cat.bmp");

	SDL_Texture* cat_texture = SDL_CreateTextureFromSurface(render, cat_surface);

	rect.x = 0;
	rect.y = 0;
	rect.w = cat_surface->w;
	rect.h = cat_surface->h;
	SDL_Event event;
	bool quit = false;
	while (quit == false) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			//else if (event.type == SDL_MOUSEMOTION) {
			//	rect.x = event.motion.x - (cat_surface->w / 2);
			//	rect.y = event.motion.y - (cat_surface->h / 2);
			//	/*	SDL_FillRect(surface, NULL, 0);
			//		SDL_BlitSurface(cat_surface, NULL, surface, &rect);
			//		SDL_UpdateWindowSurface(window);*/
			//	SDL_RenderClear(render);
			//	SDL_RenderCopy(render, cat_texture, NULL, &rect);
			//}
		}
		updatePosition();
		SDL_Delay(5);
		SDL_RenderClear(render);
		SDL_RenderCopy(render, cat_texture, NULL, &rect);
		SDL_RenderPresent(render);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}