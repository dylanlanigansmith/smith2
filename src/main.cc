#include <smith/smith.h>
#include <smith/drawutil.h>
#include <iostream>

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL_main.h>

#include <SDL3_net/SDL_net.h>
#include <SDL3_shadercross/SDL_shadercross.h>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi


SDL_Window* window = nullptr;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv){
    sdl_call<bool>(SDL_Init(SDL_INIT_VIDEO));
    window = sdl_call<SDL_Window*>(SDL_CreateWindow("Smith", 1024, 768, SDL_WINDOW_HIGH_PIXEL_DENSITY));

    sdl_call<bool>(SDL_ShaderCross_Init());
    sdl_call<bool>(SDLNet_Init());
   

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result){
    SDLNet_Quit();
    SDL_ShaderCross_Quit();
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

  SDL_Delay(1);
  return SDL_APP_CONTINUE;
}
