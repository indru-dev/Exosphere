add_subdirectory(Graphics)

add_library(OGRE STATIC
  ogre.cpp
  $<TARGET_OBJECTS:Graphics>
)

target_include_directories(OGRE
  PRIVATE
    "${CMAKE_SOURCE_DIR}/src"
)