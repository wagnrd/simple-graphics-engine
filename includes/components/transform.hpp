#ifndef SIMPLE_GRAPHICS_ENGINE_TRANSFORM_HPP
#define SIMPLE_GRAPHICS_ENGINE_TRANSFORM_HPP

#include "includes/component.hpp"
#include "includes/models/position.hpp"

class Transform: public Component {
public:
    Position position{};

public:
    Transform() = default;

    explicit Transform(Position position) : position(position)
    {}
};

#endif //SIMPLE_GRAPHICS_ENGINE_TRANSFORM_HPP