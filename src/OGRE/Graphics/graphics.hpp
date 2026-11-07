#pragma once

#include <glad/glad.h>
#include <color/color.hpp>
#include <vector/vector.hpp>


namespace ege::OGRE {

void GetShaderiv(GLuint);

class Shape {
protected:
    GLuint vao, vbo;
    GLuint shader;

    const char* vsSource;
    const char* fsSource;

    virtual void Recompile() = 0;

    Vector2f position;
    Vector2f size{1, 1};

    GLint sizeLoc;

public:
    virtual ~Shape() = default;

    virtual void Draw() = 0;
    virtual void Clean() = 0;

    void OverrideVS(const char*);
    void OverrideFS(const char*);

};

// Triangle
class Triangle : public Shape {
private:
    void Recompile() override;
    void InitializeGL();

public:
    Triangle(Vector2f);

    void Draw() override;
    void Clean() override;

};

}

