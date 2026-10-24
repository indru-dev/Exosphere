#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <core/db.hxx>
#include <vector/vector.hpp>

namespace ege {

struct CWindow {
    Vector2i size;
    const char* title;
    unsigned int framerate;
};

class Window {
private:
    GLFWwindow* window;

public:
    Window() = default;

    void Initialize(const CWindow&);
    void Update();
    void Cleanup();
    GLFWwindow* Get();

};

}


