#ifndef SIMPLE_GRAPHICS_ENGINE_MOVER_HPP
#define SIMPLE_GRAPHICS_ENGINE_MOVER_HPP

#include <memory>
#include <glm/vec2.hpp>

#include "includes/component.hpp"

class Transform;

class Mover: public Component {

    std::shared_ptr<Transform> transform;
    glm::vec2 maxPosition;

public:
    explicit Mover(const glm::vec2& maxPosition);

    void start() override;
    void update(float deltaTime) override;
};

#endif //SIMPLE_GRAPHICS_ENGINE_MOVER_HPP