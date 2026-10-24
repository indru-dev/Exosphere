#include <glad/glad.h>
#include "ogre.hpp"

using namespace ege::OGRE;
using namespace ege;

void Clear(Color color) {
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

