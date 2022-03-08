#ifndef SIMPLE_GRAPHICS_ENGINE_CAMERA_HPP
#define SIMPLE_GRAPHICS_ENGINE_CAMERA_HPP

#include <memory>

#include "includes/component.hpp"

class Node;

class Camera: public Component {

    std::shared_ptr<Node> visibleNodeTree;

public:
    [[nodiscard]] std::shared_ptr<Node> visible_node_tree() const;

protected:
    void post_update() override;
};

#endif //SIMPLE_GRAPHICS_ENGINE_CAMERA_HPP