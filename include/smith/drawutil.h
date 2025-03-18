#pragma once
#include <stdexcept>
#include <string>


#include <SDL3/SDL.h>

template <typename T>
inline T sdl_call(T result){
    if(result == NULL){
        throw std::runtime_error("SDL Error: " + std::string(SDL_GetError()));
    }
    return result;
}
template <>
inline bool sdl_call<bool>(bool result){
    if(!result){
        throw std::runtime_error("SDL Error: " + std::string(SDL_GetError()));
    }
    return result;
}

template <>
inline SDL_PropertiesID sdl_call<SDL_PropertiesID>(SDL_PropertiesID result){
    if(result == 0){
        throw std::runtime_error("SDL Error: " + std::string(SDL_GetError()));
    }
    return result;
}