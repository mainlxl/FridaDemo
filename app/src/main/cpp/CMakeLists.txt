cmake_minimum_required(VERSION 3.22.1)

project("fridademo")
include_directories(.)

# 使用GLOB收集源文件，需要正确引用变量
file(GLOB allSrc "*.c" "*.cpp")
add_library(${CMAKE_PROJECT_NAME} SHARED ${allSrc})

target_link_libraries(${CMAKE_PROJECT_NAME}
        android
        log)