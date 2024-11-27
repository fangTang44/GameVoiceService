cmake_minimum_required(VERSION 3.28.3)
project(test)

# 列出所有源文件
file(GLOB SOURCES *.cc)
message(STATUS ${SOURCES})

# 查找 libcurl 库
find_package(CURL REQUIRED)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接 libcurl 库
target_link_libraries(${PROJECT_NAME} CURL::libcurl)