add_library(Graphics OBJECT
  graphics.cpp
  triangle.cpp
)

target_include_directories(Graphics
  PUBLIC
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/tools"
    "${CMAKE_SOURCE_DIR}/tools/glad/include"
)