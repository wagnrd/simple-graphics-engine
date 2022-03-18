#ifndef SIMPLE_GRAPHICS_ENGINE_COMPONENT_HPP
#define SIMPLE_GRAPHICS_ENGINE_COMPONENT_HPP

#include <memory>

class Node;

class Component {

    friend Node;

    std::weak_ptr<Node> mNode{};

public:
    virtual ~Component() = default;

    [[nodiscard]] std::weak_ptr<Node> node()
    {
        return mNode;
    }

    virtual void start()
    {}

    virtual void update(float deltaTime)
    {}
};

#endif //SIMPLE_GRAPHICS_ENGINE_COMPONENT_HPP