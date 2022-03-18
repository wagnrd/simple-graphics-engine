#ifndef SIMPLE_GRAPHICS_ENGINE_CAMERA_HPP
#define SIMPLE_GRAPHICS_ENGINE_CAMERA_HPP

#include <memory>

#include "includes/component.hpp"

class Node;

class Camera: public Component {
public:
    [[nodiscard]] std::shared_ptr<Node> renderable_node_tree() const;
};

#endif //SIMPLE_GRAPHICS_ENGINE_CAMERA_HPP