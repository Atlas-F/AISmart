# cmake_minimum_required(VERSION 3.1)
# project(lvgl_fb)
# set(CMAKE_C_COMPILER /usr/local/arm/5.4.0/usr/bin/arm-linux-gcc)

# include_directories(.)
# include_directories(./AiSmart)

# include_directories(
#     # /usr/arm-linux-gnueabihf/include
#     /usr/arm-linux-gnueabihf/include/curl
# )

# add_subdirectory(lvgl)
# add_subdirectory(lv_drivers)
# add_subdirectory(AiSmart)

# add_executable(${PROJECT_NAME} main.c)
# target_include_directories(lvgl_fb  PRIVATE ${CMAKE_SOURCE_DIR} /opt/curl/build-arm/include/curl/ )
# # target_link_libraries(${PROJECT_NAME} PRIVATE lvgl lvgl::examples lvgl::demos lvgl::drivers ui)
# target_link_libraries(${PROJECT_NAME} 
#     PRIVATE 
#     lvgl 
#     lvgl::examples 
#     lvgl::demos 
#     lvgl::drivers 
#     ui
#     /opt/curl/build-arm/lib/libcurl.so
#     /usr/lib/x86_64-linux-gnu/libcjson.so
# )

cmake_minimum_required(VERSION 3.1)
project(lvgl_fb C)

# 设置交叉编译工具链
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)
# set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
set(CMAKE_C_COMPILER /usr/local/arm/5.4.0/usr/bin/arm-linux-gcc)
# set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)

# 设置 curl 路径
set(CURL_INCLUDE_DIR "/opt/curl/build-arm/include")
set(CURL_LIBRARY "/opt/curl/build-arm/lib/libcurl.so")

# 添加包含目录
include_directories(
    .
    ./AiSmart
    ${CURL_INCLUDE_DIR}
)

# 添加 LVGL 子目录
add_subdirectory(lvgl)
add_subdirectory(lv_drivers)
add_subdirectory(AiSmart)

# 创建可执行文件
add_executable(${PROJECT_NAME} main.c)

# 链接库文件
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
    lvgl 
    lvgl::examples 
    lvgl::demos 
    lvgl::drivers
    ui
    ${CURL_LIBRARY}
)