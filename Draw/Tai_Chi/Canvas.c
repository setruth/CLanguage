
//画板
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int CanvasInit(int width, int height, const char *name) {
   if( SDL_Init(SDL_INIT_VIDEO) < 0) {
      printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
      return 1;
   }
   window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
   if(window == NULL) {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
      return 1;
   }
   renderer = SDL_CreateRenderer(window, -1, 0);
   return 0;
}

int CanvasSetColor(int r, int g, int b, int a) {
   SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void CanvasDrawPoint(double x, double y) {
   SDL_RenderDrawPoint(renderer, (int)x, (int)y);
}

int CanvasUpdate(void) {
   SDL_RenderPresent(renderer);
}

int CanvasDeserty(void) {
   SDL_Event myEvent;
   int quit = 0;
   while (!quit) {
      while (SDL_PollEvent(&myEvent)) {
         switch (myEvent.type) {
            case SDL_QUIT:
               quit = 1;
               break;
         }
      }
   }
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
}
