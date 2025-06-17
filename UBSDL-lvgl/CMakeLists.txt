

cmake_minimum_required(VERSION 3.1)
project(lvgl_sdl C)

set(CMAKE_FIND_LIBRARY_PREFIXES "lib")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".so" ".a")

# find_package(PkgConfig REQUIRED)
# pkg_check_modules(CURL REQUIRED libcurl)
# pkg_check_modules(CJSON REQUIRED libcjson)


include_directories(.)
include_directories(./AiSmart)

add_subdirectory(lvgl)
add_subdirectory(lv_drivers)
add_subdirectory(AiSmart)

add_executable(${PROJECT_NAME} main.c )

target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
    lvgl 
    lvgl::examples 
    lvgl::demos 
    lvgl::drivers 
    SDL2 
    ui
    /usr/lib/x86_64-linux-gnu/libcurl.so
    /usr/lib/x86_64-linux-gnu/libcjson.so
)

# target_link_libraries(${PROJECT_NAME} PRIVATE lvgl lvgl::examples lvgl::demos lvgl::drivers  SDL2 ui)
# target_link_libraries(lvgl_sdl
#     PRIVATE
#      /usr/lib/x86_64-linux-gnu/libcurl.so
#     /usr/lib/x86_64-linux-gnu/libcjson.so
#     # ...existing code...
# )