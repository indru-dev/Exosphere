#include "graphics.hpp"
#include <logger/logger.hpp>
#include <string>

using namespace ege::OGRE;

void ege::OGRE::GetShaderiv(GLuint shader) {
    int success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::string msg = "SHADER ERROR: " + (std::string) infoLog + '\n';
        logger::LOG("OGRE", msg.c_str());
    }
}

void Shape::OverrideVS(const char* source) {
    vsSource = source;
    Recompile();
}

void Shape::OverrideFS(const char* source) {
    fsSource = source;
    Recompile();
}

