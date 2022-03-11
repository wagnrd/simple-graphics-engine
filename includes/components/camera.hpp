#ifndef SIMPLE_GRAPHICS_ENGINE_CAMERA_HPP
#define SIMPLE_GRAPHICS_ENGINE_CAMERA_HPP

#include <memory>

#include "includes/component.hpp"

class Node;

class Camera: public Component {

    std::shared_ptr<Node> renderableNodeTree = std::make_shared<Node>();

public:
    [[nodiscard]] std::shared_ptr<Node> renderable_node_tree() const;

protected:
    void post_update() override;

private:
    std::shared_ptr<Node> copy_node(const std::shared_ptr<Node>& node);
};

#endif //SIMPLE_GRAPHICS_ENGINE_CAMERA_HPP