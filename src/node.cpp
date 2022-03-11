#include "includes/node.hpp"

void Node::update(float deltaTime)
{
    for (auto&[_, component]: mComponents)
        component->update(deltaTime);

    for (auto& child: mChildren)
        child->update(deltaTime);
}

void Node::post_update()
{
    for (auto&[_, component]: mComponents)
        component->post_update();

    for (auto& child: mChildren)
        child->post_update();
}

std::shared_ptr<Node> Node::emplace_child(const std::string& childName)
{
    auto node = std::make_shared<Node>(childName);
    add_child(node);

    return node;
}

void Node::add_child(const std::shared_ptr<Node>& node)
{
    mChildren.push_back(node);
    node->mParent = shared_from_this();
}

void Node::remove_child(const std::string& childName)
{
    auto it = std::find_if(
            mChildren.begin(), mChildren.end(), [&](const std::shared_ptr<Node>& child) {
                return child->mName == childName;
            }
    );

    if (it == mChildren.end())
        return;

    mChildren.erase(it);
}

void Node::remove_child(size_t index)
{
    if (index >= mChildren.size())
        return;

    mChildren.erase(mChildren.begin() + index);
}

void Node::remove_all_children()
{
    mChildren.clear();
}

std::shared_ptr<Node> Node::find_child(const std::string& childName) const
{
    for (const auto& child: mChildren)
    {
        if (child->mName == childName)
            return child;
    }

    throw std::runtime_error("No child found with name '" + childName + " in node '" + mName + "'");
}

std::shared_ptr<Node> Node::find_child(size_t index) const
{
    if (index >= mChildren.size())
        throw std::runtime_error("No child found at index '" + std::to_string(index) + " in node '" + mName + "'");

    return mChildren.at(index);
}

/*******************
* Getters / Setters*
********************/
const std::string& Node::name() const
{
    return mName;
}

void Node::set_name(const std::string& name)
{
    this->mName = name;
}

std::weak_ptr<Node> Node::parent() const
{
    return mParent;
}

size_t Node::children_count() const
{
    return mChildren.size();
}