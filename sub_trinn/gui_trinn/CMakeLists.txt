cmake_minimum_required(VERSION 3.14)
project(gui_trinn VERSION 0.0.1)

set (trinn_h
    include/gui_trinn/trinn.h
)

set (trinn_cpp
     trinn.cpp
)

set (CMAKE_AUTORCC ON)
find_package(Qt5Core)
find_package(Qt5Qml)
find_package(Qt5Quick)

add_library(gui_trinn SHARED ${trinn_h} ${trinn_cpp} trinn_rc.qrc)

set_target_properties(gui_trinn PROPERTIES PREFIX "plug_" OUTPUT_NAME "trinn")
target_link_libraries(gui_trinn lib_baseAF lib_quickAF lib_currencyAF Qt5::Core Qt5::Quick Qt5::Qml)
target_include_directories(gui_trinn
    PUBLIC  include
    PRIVATE include/gui_trinn
    PUBLIC $<TARGET_PROPERTY:lib_baseAF,INTERFACE_INCLUDE_DIRECTORIES>
    PUBLIC $<TARGET_PROPERTY:lib_quickAF,INTERFACE_INCLUDE_DIRECTORIES>
    PUBLIC $<TARGET_PROPERTY:lib_currencyAF,INTERFACE_INCLUDE_DIRECTORIES>
)
