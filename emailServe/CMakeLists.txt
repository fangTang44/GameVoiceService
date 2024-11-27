cmake_minimum_required(VERSION 3.28.3)

# CMAKE_CURRENT_SOURCE_DIR  当前CMakeLists.txt的路径
file(GLOB_RECURSE EMAILSERVESRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)
message("Current source dir: ${EMAILSERVESRC}")

add_library(mylib ${EMAILSERVESRC})

# 为 mylib 目标添加头文件路径
target_include_directories(mylib
    PUBLIC
        # 这些路径将被传递给依赖于 mylib 的目标
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        # 这些路径仅对 mylib 内部使用
        ${CMAKE_CURRENT_BINARY_DIR}
)
