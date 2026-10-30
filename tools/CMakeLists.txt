# GLAD
add_library(GLAD STATIC
  "${CMAKE_CURRENT_SOURCE_DIR}/glad/src/glad.c"
)

target_include_directories(GLAD
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/glad/include"
)


# WOAH
add_library(WOAH STATIC
  woah/woah.cpp
)

target_include_directories(WOAH
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/woah"
)

