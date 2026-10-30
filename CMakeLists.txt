cmake_minimum_required(VERSION 4.0)

project(Exosphere
  VERSION 1.0
  LANGUAGES C CXX
)

find_package(glfw3 3.3 REQUIRED)

add_subdirectory(tools)
add_subdirectory(src)

target_include_directories(Exosphere
  PRIVATE
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/tools"
)

install(TARGETS Exosphere
  RUNTIME DESTINATION bin
)
