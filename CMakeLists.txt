cmake_minimum_required(VERSION 3.18)

project(smith C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_COLOR_DIAGNOSTICS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON )
set(EXECUTABLE_NAME ${PROJECT_NAME})


macro(fw_file_glob glob variable)
  file(${glob} ${variable} CONFIGURE_DEPENDS ${ARGN})
endmacro()

set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type" FORCE)

#enable assertions
string( REPLACE "-DNDEBUG" "" CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
set(TP_DIR ${PROJECT_SOURCE_DIR}/3rdparty)

set(BUILD_SHARED_LIBS OFF)
set(SDL_STATIC ON)

add_subdirectory(${TP_DIR}/SDL )

set(SDLSHADERCROSS_VENDORED ON)
set(SDLSHADERCROSS_CLI_STATIC ON)
add_subdirectory(${TP_DIR}/SDL_shadercross)

set(IMGUI_DIR ${TP_DIR}/imgui)
set(IMGUI_INCLUDES ${IMGUI_DIR})
set(IMGUI_SRCS 
    ${IMGUI_DIR}/imgui.cpp 
    ${IMGUI_DIR}/imgui_draw.cpp 
    ${IMGUI_DIR}/imgui_widgets.cpp 
    ${IMGUI_DIR}/imgui_demo.cpp 
    ${IMGUI_DIR}/imgui_tables.cpp  
    ${IMGUI_DIR}/misc/cpp/imgui_stdlib.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdl3.cpp 
    ${IMGUI_DIR}/backends/imgui_impl_sdlgpu3.cpp  
    # ${IMGUI_DIR}/backends/imgui_impl_sdlrenderer3.cpp 
    # ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
    # ${IMGUI_DIR}/misc/freetype/imgui_freetype.cpp
)
set(SRCS "${SRCS}" "${IMGUI_SRCS}")
set(INCLUDES "${INCLUDES}" "${IMGUI_INCLUDES}" )

set(COMPILE_DEFS "")

set(INCLUDES  
    ${INCLUDES} 
    ${PROJECT_SOURCE_DIR}/include 
)


fw_file_glob(GLOB_RECURSE SMITH_SRCS "${PROJECT_SOURCE_DIR}/src/*.cc")
set(SRCS "${SRCS}" "${SMITH_SRCS}")

add_executable(${EXECUTABLE_NAME} ${SRCS})



target_include_directories(${EXECUTABLE_NAME} PRIVATE ${INCLUDES})
target_compile_definitions(${EXECUTABLE_NAME} PRIVATE ${COMPILE_DEFS})
target_link_libraries(${EXECUTABLE_NAME} 
PUBLIC
  SDL3::SDL3
  SDL3_shadercross::SDL3_shadercross-static
)