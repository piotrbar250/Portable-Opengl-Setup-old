cmake_minimum_required(VERSION 3.10)
project(app)

# add_subdirectory(vendor/glfw-3.3.9)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/imgui)

file(GLOB_RECURSE app_sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE app_headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")
add_executable(app ${app_sources} ${app_headers})


target_include_directories(app PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(app PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/UI")

target_link_libraries(app glfw glad imgui)