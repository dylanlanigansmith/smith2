#include <smith/smith.h>
#include <smith/drawutil.h>
#include <iostream>

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL_main.h>

SDL_Window* window = nullptr;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv){
    sdl_call<bool>(SDL_Init(SDL_INIT_VIDEO));
    window = sdl_call<SDL_Window*>(SDL_CreateWindow("Smith", 1024, 768, SDL_WINDOW_HIGH_PIXEL_DENSITY));
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result){
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){
    if(event->type == SDL_EVENT_QUIT){
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}
SDL_AppResult SDL_AppIterate(void *appstate){
  




  return SDL_APP_CONTINUE;
}
