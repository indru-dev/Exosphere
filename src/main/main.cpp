#include <woah/woah.hpp>
#include <window/window.hpp>
#include <OGRE/ogre.hpp>
#include <OGRE/Graphics/graphics.hpp>

// Namespaces

using namespace woah;
using namespace ege;

// Declarations

Runtime rt;
Runtime* IRuntime::rt = rt;
CWindow cwin{{800, 600}, "Exosphere", 120};
Window window;

// Runtime

int main() {

    rt.Initialize();
    window.Initialize(cwin);

    // Exec

    OGRE::Triangle triangle({200, 200});

    // Loop
    while (!rt.ShouldClose()) {
        // Top-level
        OGRE::Clear(Color(0.3, 0.3, 0.3, 1.0));


        // Update

        triangle.Draw();


        // Bottom-level
        window.Update();
    }

    // Cleanup

    triangle.Clean();

    window.Cleanup();


}



