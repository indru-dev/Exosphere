#include "graphics.hpp"


using namespace ege::OGRE;

void Shape::OverrideVS(const char* source) {
    vsSource = source;
    Recompile();
}

void Shape::OverrideFS(const char* source) {
    fsSource = source;
    Recompile();
}

