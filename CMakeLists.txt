cmake_minimum_required(VERSION 3.10)
project(app)

add_subdirectory(vendor/glfw-3.3.9)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/imgui)

add_executable(app src/main.cpp)

target_link_libraries(app glfw glad imgui)