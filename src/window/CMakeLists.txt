add_library(Window STATIC
  window.cpp
)

target_link_libraries(Window
  PUBLIC
    GLAD
)

target_include_directories(Window
  PUBLIC
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/tools/glad/include"
    "${CMAKE_SOURCE_DIR}/tools"
)