#include <stdio.h>

extern "C" {
#include <SDL.h>
#include <SDL_thread.h>
#include <SDL_image.h>
}

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("SDL-Tutorial-03", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

	SDL_Surface* surface = SDL_GetWindowSurface(window);
	SDL_Surface* face1 = SDL_LoadBMP("face1.bmp");
	SDL_Surface* face2 = SDL_LoadBMP("face2.bmp");
	SDL_Surface* current = face1;
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	SDL_BlitSurface(face1, NULL, surface, NULL);
	//SDL Event
	SDL_Event event;
	bool quit = false;
	while (quit == false) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				printf("Close the process\n");
				quit = true;
				//exit(0);
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					current = face1;
					SDL_BlitSurface(face1, NULL, surface, &rect);
				}
				else if (event.button.button == SDL_BUTTON_RIGHT) {
					current = face2;
					SDL_BlitSurface(face2, NULL, surface, &rect);
				}
			}
			else if (event.type == SDL_KEYDOWN) {
				int code = event.key.keysym.sym;
				if (code == SDLK_UP) {
					rect.y = rect.y - 10;
				}
				else if (code == SDLK_DOWN) {
					rect.y = rect.y + 10;
				}
				else if (code == SDLK_LEFT) {
					rect.x = rect.x - 10;
				}
				else if (code == SDLK_RIGHT) {
					rect.x = rect.x + 10;
				}
				SDL_FillRect(surface, NULL, 0);
				SDL_BlitSurface(current, NULL, surface, &rect);
			}
			SDL_UpdateWindowSurface(window);
		}
	}
	SDL_UpdateWindowSurface(window);
	//SDL_Delay(3000);
	SDL_FreeSurface(surface);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}