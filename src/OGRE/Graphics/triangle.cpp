#include "graphics.hpp"
#include <string>
#include <logger/logger.hpp>
using namespace ege::OGRE;

const char* vsCache = R"(
    #version 460 core

    layout (location = 0) in vec2 aPos;

    uniform vec2 uScale;

    void main() {
        vec2 transform = (aPos * uScale);

        gl_Position = vec4(aPos, 0.0, 1.0);
    }
)";

const char* fsCache = R"(
    #version 460 core

    out vec4 FragColor;

    void main() {
        FragColor = vec4(0.7, 0.95, 0.95, 1.0);
    }
)";

void Triangle::Recompile() {

    glDeleteProgram(shader);

    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vsSource, NULL);
    glCompileShader(vs);

    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fsSource, NULL);
    glCompileShader(fs);

    shader = glCreateProgram();
    glAttachShader(shader, vs);
    glAttachShader(shader, fs);
    glLinkProgram(shader);

    glDeleteShader(vs);
    glDeleteShader(fs);

}


Triangle::Triangle(Vector2f Scale) {

    this->size = Scale;

    InitializeGL();

    // Uniforms
    sizeLoc = glGetUniformLocation(shader, "uScale");

}


void Triangle::InitializeGL() {

    vsSource = vsCache;
    fsSource = fsCache;

    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vsSource, NULL);
    glCompileShader(vs);

    GetShaderiv(vs);

    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fsSource, NULL);
    glCompileShader(fs);

    GetShaderiv(fs);

    shader = glCreateProgram();
    glAttachShader(shader, vs);
    glAttachShader(shader, fs);
    glLinkProgram(shader);

    glDeleteShader(vs);
    glDeleteShader(fs);

    float vertices[] = {
        -0.5f, 0.0f,
        0.5f, -0.5f,
        0.0f, 0.5f
    };

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(vertices),
        vertices,
        GL_STATIC_DRAW
    );

    glVertexAttribPointer(
        0,
        2,
        GL_FLOAT,
        GL_FALSE,
        2 * sizeof(float),
        (void*) 0
    );
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

}

void Triangle::Draw() {

    glUseProgram(shader);

    glUniform2f(sizeLoc, size.x, size.y);

    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);

}

void Triangle::Clean() {

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(shader);

}

