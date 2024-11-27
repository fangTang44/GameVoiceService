cmake_minimum_required(VERSION 3.28.3)
project(GameVoiceService)

add_subdirectory(emailServe)



# CMAKE_ARCHIVE_OUTPUT_DIRECTORY：用于静态库（.lib, .a）。
# CMAKE_LIBRARY_OUTPUT_DIRECTORY：用于动态链接库（.dll, .so, .dylib）。
# CMAKE_RUNTIME_OUTPUT_DIRECTORY：用于可执行文件（.exe）。
# 设置所有目标的输出路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)