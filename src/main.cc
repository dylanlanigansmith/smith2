#include <smith/smith.h>
#include <iostream>
#include <SDL3/SDL.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Hello, World!", 800, 600, SDL_WINDOW_HIGH_PIXEL_DENSITY);
    puts("Hello, World!");
    std::cout << "this is CPP" << std::endl;
    while(true) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                break;
            }
        }
    }
    SDL_DestroyWindow(window);
    return 0;
}