#ifndef SIMPLE_GRAPHICS_ENGINE_POSITION_HPP
#define SIMPLE_GRAPHICS_ENGINE_POSITION_HPP

#include <cstdint>

class Position {
public:
    float x = 0;
    float y = 0;

    Position() = default;

    Position(float x, float y) : x(x), y(y)
    {}
};

#endif //SIMPLE_GRAPHICS_ENGINE_POSITION_HPP