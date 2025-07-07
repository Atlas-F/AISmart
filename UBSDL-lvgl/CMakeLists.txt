
cmake_minimum_required(VERSION 3.10)
project(lvgl_sdl C)

# 设置 CMake 构建类型为 Debug，生成调试信息并禁用优化
set(CMAKE_BUILD_TYPE Debug)

# 添加调试编译选项（如果上面的设置不生效，可以强制添加）
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g3 -O0 -ggdb3 -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -O0 -ggdb3 -fno-omit-frame-pointer")

# 可选：显示详细的编译命令，便于排查问题
set(CMAKE_VERBOSE_MAKEFILE ON)

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
    # /opt/openssl-and-curl/curl-installx86/lib/libcurl.so.4
    /usr/lib/x86_64-linux-gnu/libcurl.so.4
    /usr/lib/x86_64-linux-gnu/libcjson.so.1
)

# target_link_libraries(${PROJECT_NAME} PRIVATE lvgl lvgl::examples lvgl::demos lvgl::drivers  SDL2 ui)
# target_link_libraries(lvgl_sdl
#     PRIVATE
#      /usr/lib/x86_64-linux-gnu/libcurl.so
#     /usr/lib/x86_64-linux-gnu/libcjson.so
#     # ...existing code...
# )