add_library(Window STATIC
  window.cpp
)

target_include_directories(Window
  PUBLIC
    "${CMAKE_SOURCE_DIR}/src"
)