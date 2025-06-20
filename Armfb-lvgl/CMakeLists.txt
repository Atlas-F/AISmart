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


# 不支持https，但是curl为新编译支持版本
cmake_minimum_required(VERSION 3.1)
project(lvgl_fb C)

# 设置交叉编译工具链
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)
# set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
set(CMAKE_C_COMPILER /usr/local/arm/5.4.0/usr/bin/arm-linux-gcc)
# set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)


# 修改为您的实际 OpenSSL 安装路径
# set(OPENSSL_ROOT_DIR "/opt/opensslcurl/install-openssl")
set(OPENSSL_INCLUDE_DIR "/opt/opensslcurl/install-openssl/include")
set(OPENSSL_LIBRARY_DIR "/opt/opensslcurl/install-openssl/lib")

# 设置 curl 路径
set(CURL_ROOT "/opt/opensslcurl/install-libcurl")
set(CURL_INCLUDE_DIR "/opt/opensslcurl/install-libcurl/include")
set(CURL_LIBRARY "/opt/opensslcurl/install-libcurl/lib/libcurl.so")

# 添加包含目录
include_directories(
    .
    ./AiSmart
    ${CURL_INCLUDE_DIR}
    ${OPENSSL_INCLUDE_DIR}
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
    "${OPENSSL_LIBRARY_DIR}/libssl.so"
    "${OPENSSL_LIBRARY_DIR}/libcrypto.so"    
    
)

set(CMAKE_INSTALL_RPATH "${OPENSSL_LIBRARY_DIR};${CURL_ROOT}/lib")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)




# cmake_minimum_required(VERSION 3.1)
# project(lvgl_fb C)

# # ======================== 交叉编译设置 ========================
# set(CMAKE_SYSTEM_NAME Linux)
# set(CMAKE_SYSTEM_PROCESSOR arm)

# # 明确指定交叉编译工具链
# set(CMAKE_C_COMPILER /usr/local/arm/5.4.0/usr/bin/arm-linux-gcc)

# # 设置目标系统环境（避免使用宿主机的库）
# # set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# # set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
# # set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
# # set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# # ======================== 设置库路径 ========================
# # 设置自定义 cURL 路径
# set(CURL_ROOT "/opt/curl-armssl")
# set(CURL_INCLUDE_DIR "${CURL_ROOT}/include")
# set(CURL_LIBRARY_DIR "${CURL_ROOT}/lib")

# # 设置 OpenSSL 路径（如果 cURL 依赖 OpenSSL）
# set(OPENSSL_ROOT_DIR "/opt/openssl111f")  # 修改为您的实际路径
# set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")
# set(OPENSSL_LIBRARY_DIR "${OPENSSL_ROOT_DIR}/lib")

# # ======================== 添加包含目录 ========================
# include_directories(
#     .
#     ./AiSmart
#     ${CURL_INCLUDE_DIR}
#     ${OPENSSL_INCLUDE_DIR}  # 添加 OpenSSL 头文件
# )

# # 添加链接目录
# link_directories(
#     ${CURL_LIBRARY_DIR}
#     ${OPENSSL_LIBRARY_DIR}
# )

# # ======================== 添加子目录 ========================
# add_subdirectory(lvgl)
# add_subdirectory(lv_drivers)
# add_subdirectory(AiSmart)

# # ======================== 创建可执行文件 ========================
# add_executable(${PROJECT_NAME} main.c)

# # ======================== 链接库文件 ========================
# target_link_libraries(${PROJECT_NAME} 
#     PRIVATE 
#     lvgl 
#     lvgl::examples 
#     lvgl::demos 
#     lvgl::drivers
#     ui
#     ${CURL_LIBRARY}
#     ${OPENSSL_LIBRARIES}  # 添加OpenSSL库链接
#     # curl  # 使用库名而非路径
#     # ssl   # OpenSSL 依赖
#     # crypto # OpenSSL 依赖
#     # z     # zlib 依赖
# )

# # ======================== 附加设置 ========================
# # 设置 rpath 确保运行时找到库
# set(CMAKE_INSTALL_RPATH "${CURL_LIBRARY_DIR}")
# set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

# # 添加静态链接选项（如果需要）
# # set(CMAKE_EXE_LINKER_FLAGS "-static")