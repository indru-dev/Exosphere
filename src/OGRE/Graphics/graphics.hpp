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

    virtual void Recompile() = 0;

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

public:
    Triangle();

    void Draw() override;
    void Clean() override;

};

}

