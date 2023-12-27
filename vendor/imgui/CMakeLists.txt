# cmake_minimum_required(VERSION 3.10)
# project(imgui)

# add_library(imgui)
# file(GLOB_RECURSE imgui_sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# target_sources(imgui "${imgui_sources}")

cmake_minimum_required(VERSION 3.10)
project(imgui)

# Assuming you want to create a static library
add_library(imgui STATIC)

# Use file(GLOB_RECURSE ...) to find all source files
file(GLOB_RECURSE IMGUI_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.cpp")

# Add these source files to your library
target_sources(imgui PRIVATE ${IMGUI_SOURCES})

target_include_directories(imgui PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/imgui")