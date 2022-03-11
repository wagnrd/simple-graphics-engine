#include "includes//engine.hpp"
#include "includes/node.hpp"
#include "includes/components/camera.hpp"

std::shared_ptr<Node> Camera::renderable_node_tree() const
{
    return renderableNodeTree;
}

void Camera::post_update()
{
    // gather all visible nodes and build a separate node tree (copy)
    // currently it just copies the whole node tree
    renderableNodeTree = copy_node(Engine::get()->scene());
}

std::shared_ptr<Node> Camera::copy_node(const std::shared_ptr<Node>& node)
{
    auto nodeCopy = std::make_shared<Node>(*node);
    nodeCopy->remove_all_children();

    for (size_t i = 0; i < node->children_count(); ++i)
    {
        auto childCopy = copy_node(node->find_child(i));
        nodeCopy->add_child(childCopy);
    }

    return nodeCopy;
}