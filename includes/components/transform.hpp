#ifndef SIMPLE_GRAPHICS_ENGINE_TRANSFORM_HPP
#define SIMPLE_GRAPHICS_ENGINE_TRANSFORM_HPP

#include <utility>
#include <glm/vec2.hpp>

#include "includes/component.hpp"

class Transform: public Component {
public:
    glm::vec2 position{};
    float rotation{};
    glm::vec2 scale{1, 1};

public:
    Transform() = default;

    Transform(const glm::vec2& position, float rotation, const glm::vec2& scale)
            : position(position),
              rotation(rotation),
              scale(scale)
    {}
};

#endif //SIMPLE_GRAPHICS_ENGINE_TRANSFORM_HPP