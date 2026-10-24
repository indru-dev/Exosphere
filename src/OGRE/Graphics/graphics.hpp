#pragma once

#include <glad/glad.h>
#include <color/color.hpp>


namespace ege::OGRE {

class Shape {
protected:
    GLuint vao, vbo;
    GLuint shader;

    const char* vsSource;
    const char* fsSource;

    virtual void Recompile();

public:
    virtual void Draw();
    virtual void Clean();

    void OverrideVS(const char*);
    void OverrideFS(const char*);

};

// Triangle
class Triangle : public Shape {
private:
    void Recompile() override;

public:
    Triangle() = default;
    void Draw() override;
    void Clean() override;

};

}

