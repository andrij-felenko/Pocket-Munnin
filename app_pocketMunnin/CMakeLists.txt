cmake_minimum_required(VERSION 3.14)
project(app_pocketMunnin)

find_package(Qt5Core)

add_executable(app_pocketMunnin main.cpp)
target_include_directories(app_pocketMunnin PUBLIC include
    PUBLIC $<TARGET_PROPERTY:plug_trinn,INTERFACE_INCLUDE_DIRECTORIES>)
target_link_libraries(app_pocketMunnin plug_trinn Qt5::Core)
