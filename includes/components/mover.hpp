#ifndef SIMPLE_GRAPHICS_ENGINE_MOVER_HPP
#define SIMPLE_GRAPHICS_ENGINE_MOVER_HPP

#include <memory>

#include "includes/component.hpp"

class Transform;

class Mover: public Component {

    std::shared_ptr<Transform> transform;
    Position basePosition;
    Position maxPosition;

public:
    explicit Mover(const Position& maxPosition);

    void start() override;
    void update(float deltaTime) override;
};

#endif //SIMPLE_GRAPHICS_ENGINE_MOVER_HPP