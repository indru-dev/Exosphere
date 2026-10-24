add_library(Graphics OBJECT
  graphics.cpp
  triangle.cpp
)

target_include_directories(Graphics
  PUBLIC
    "${CMAKE_SOURCE_DIR}/src"
)