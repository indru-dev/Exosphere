#include "window.hpp"
#include <vector/vector.hpp>


namespace ege {


    class WindowCoordinates { public:

        static Vector2f ToNDC(
            float x,
            float y,
            CWindow window
        ) {
            return {
                (2.0f * x / window.size.x) - 1.0f,
                1.0f - (2.0f * y / window.size.y)
            };
        }

    };

    using WC = WindowCoordinates;

}



