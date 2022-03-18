#include "includes/node.hpp"
#include "includes/components/transform.hpp"
#include "includes/components/mover.hpp"

Mover::Mover(const glm::vec2& maxPosition) : maxPosition(maxPosition)
{}

void Mover::start()
{
    transform = node().lock()
                      ->find_component<Transform>()
                      .value();
}

void Mover::update(float deltaTime)
{
    auto basePosition = transform->position;
    auto x = transform->position.x;
    auto y = transform->position.y;

    if (x >= basePosition.x && x < maxPosition.x && y == basePosition.y)
        ++x;
    else if (x == maxPosition.x && y >= basePosition.y && y < maxPosition.y)
        ++y;
    else if (y == maxPosition.y && x <= maxPosition.x && x > basePosition.x)
        --x;
    else
        --y;

    transform->position.x = x;
    transform->position.y = y;
}