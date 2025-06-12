cmake_minimum_required(VERSION 3.1)
project(lvgl_fb)
set(CMAKE_C_COMPILER /usr/local/arm/5.4.0/usr/bin/arm-linux-gcc)

include_directories(.)
include_directories(./AiSmart)

add_subdirectory(lvgl)
add_subdirectory(lv_drivers)
add_subdirectory(AiSmart)

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE lvgl lvgl::examples lvgl::demos lvgl::drivers ui)