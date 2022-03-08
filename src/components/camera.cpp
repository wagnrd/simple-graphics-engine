#include "includes/node.hpp"
#include "includes/components/camera.hpp"

std::shared_ptr<Node> Camera::visible_node_tree() const
{
    return visibleNodeTree;
}

void Camera::post_update()
{
    // gather all visible nodes and build a separate node tree (copy)
}