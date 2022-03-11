#ifndef SIMPLE_GRAPHICS_ENGINE_COMPONENT_HPP
#define SIMPLE_GRAPHICS_ENGINE_COMPONENT_HPP

#include <memory>

class Node;

class Component {

    friend Node;

    std::weak_ptr<Node> mNode{};

public:
    virtual ~Component() = default;

    std::weak_ptr<Node> node()
    {
        return mNode;
    }

protected:
    virtual void start()
    {}

    virtual void update(float deltaTime)
    {}

    virtual void post_update()
    {}
};

#endif //SIMPLE_GRAPHICS_ENGINE_COMPONENT_HPP