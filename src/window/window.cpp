#define GLFW_INCLUDE_NONE
#include <GLFW./glfw3.h>
#include <glad/glad.h>
#include <window/window.hpp>
#include <iostream>
#include <woah/woah.hpp>
#include <core/db.hxx>
#include <logger/logger.hpp>

using namespace ege;
using namespace logger;

woah::IRuntime rti;
const char* ID = "WINDOW";

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0 ,0, width, height);
}

void Window::Initialize(const CWindow& info) {

    if(!glfwInit()) {
        LOG(ID, "Failed to initiallize GLFW (glfwInit)");
        rti.SignalClose();
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, db::GL_VERSION_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, db::GL_VERSION_MINOR);
    glfwWindowHint(GLFW_OPENGL_PROFILE, db::GL_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    window = glfwCreateWindow(info.size.x, info.size.y, info.title, nullptr, nullptr);
    if(!window) {
        LOG(ID, "Failed to initialize GLFW window (glfwCreateWindow)");
        rti.SignalClose();
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        LOG(ID, "Failed to initialize GLAD (gladLoadGLLoader)");
        Cleanup();
        return;
    }

}

void Window::Update() {
    glfwSwapBuffers(window);
    glfwPollEvents();

    if(glfwWindowShouldClose(window)) rti.SignalClose();
}

void Window::Cleanup() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

GLFWwindow* Window::Get() {
    return window;
}

