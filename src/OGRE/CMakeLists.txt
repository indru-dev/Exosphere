add_subdirectory(Graphics)

add_library(OGRE STATIC
  ogre.cpp
  $<TARGET_OBJECTS:Graphics>
)

target_link_libraries(OGRE
  PUBLIC
    GLAD
    glfw3
)

target_include_directories(OGRE
  PUBLIC
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/tools/glad/include"
    "${CMAKE_SOURCE_DIR}/tools"
)