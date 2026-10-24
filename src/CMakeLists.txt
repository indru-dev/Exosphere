add_subdirectory(OGRE)
add_subdirectory(window)

add_executable(Exosphere main/main.cpp)

target_link_libraries(Exosphere
  PRIVATE
    OGRE
    Window
)

target_include_directories(Exosphere
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)