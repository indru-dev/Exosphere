add_subdirectory(OGRE)
add_subdirectory(window)

add_executable(Exosphere main/main.cpp)

target_link_libraries(Exosphere
  PRIVATE
    OGRE
    Window
    GLAD
    WOAH
)

target_include_directories(Exosphere
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}/tools"
    "${CMAKE_CURRENT_SOURCE_DIR}/woah"
)