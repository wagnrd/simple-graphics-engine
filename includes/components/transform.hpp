#ifndef SIMPLE_GRAPHICS_ENGINE_TRANSFORM_HPP
#define SIMPLE_GRAPHICS_ENGINE_TRANSFORM_HPP

#include <utility>
#include <glm/vec2.hpp>

#include "includes/component.hpp"

class Transform: public Component {
public:
    glm::vec2 position;

public:
    Transform() = default;

    explicit Transform(const glm::vec2& position) : position(position)
    {}
};

#endif //SIMPLE_GRAPHICS_ENGINE_TRANSFORM_HPP