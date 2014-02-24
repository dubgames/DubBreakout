cmake_minimum_required (VERSION 2.8)
project (DubBreakout)

set (SDL_IN_SUBDIRECTORY 1)


configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
  )
  
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

include(./FindSDL2.cmake)
include_directories(SDL2_INCLUDE_DIR)
include_directories(SDL2_IMAGE_INCLUDE_DIR)
include_directories(SDL2_TTF_INCLUDE_DIR)
include_directories(SDL2_MIXER_INCLUDE_DIR)

include_directories("${PROJECT_BINARY_DIR}")

file(GLOB HEADERS "./src/*.h")
include_directories(${HEADERS})

file(GLOB SOURCES "./src/*.cpp")
add_executable(Breakout ${SOURCES}	)

target_link_libraries(Breakout ${SDL2_LIBRARY})
target_link_libraries(Breakout ${SDL2_IMAGE_LIBRARY})
target_link_libraries(Breakout ${SDL2_TTF_LIBRARY})
target_link_libraries(Breakout ${SDL2_MIXER_LIBRARY})



