#include "includes/engine.hpp"
#include "includes/components/camera.hpp"

std::shared_ptr<Node> Camera::renderable_node_tree() const
{
    // ToDo: return culled node tree only containing nodes that can be seen from the camera
    return Engine::get()->scene();
}