#ifndef SIMPLE_GRAPHICS_ENGINE_NODE_HPP
#define SIMPLE_GRAPHICS_ENGINE_NODE_HPP

#include <unordered_map>
#include <typeinfo>
#include <stdexcept>
#include <memory>
#include <utility>
#include <string>
#include <optional>
#include <deque>

#include "includes/component.hpp"

class Node: public std::enable_shared_from_this<Node> {

    std::weak_ptr<Node> mParent;
    std::string mName{};
    std::unordered_map<const char*, std::shared_ptr<Component>> mComponents{};
    std::deque<std::shared_ptr<Node>> mChildren{};

public:
    explicit Node(std::string name = "") : mName(std::move(name))
    {}

    void update(float deltaTime);
    void post_update();

    std::shared_ptr<Node> emplace_child(const std::string& childName = "");
    void add_child(const std::shared_ptr<Node>& node);
    void remove_child(const std::string& childName);
    void remove_child(size_t index);
    void remove_all_children();
    std::shared_ptr<Node> find_child(const std::string& childName) const;
    std::shared_ptr<Node> find_child(size_t index) const;

    template<class T, typename... Args>
    std::shared_ptr<T> emplace_component(Args... args)
    {
        auto component = std::make_shared<T>(args...);
        component->mNode = shared_from_this();
        auto typeName = typeid(T).name();
        mComponents[typeName] = component;
        component->start();

        return component;
    }

    template<class T>
    void remove_component()
    {
        mComponents.erase(typeid(T).name());
    }

    template<class T>
    std::shared_ptr<T> get_component() const
    {
        auto typeName = typeid(T).name();
        auto it = mComponents.find(typeName);

        if (it == mComponents.end())
            throw std::runtime_error("Component '" + std::string(typeName) + "' not found in node '" + mName + "'");

        return std::dynamic_pointer_cast<T>(it->second);
    }

    // Getters and Setters
    [[nodiscard]] const std::string& name() const;
    void set_name(const std::string& name);
    [[nodiscard]] std::weak_ptr<Node> parent() const;
    [[nodiscard]] size_t children_count() const;
};

#endif //SIMPLE_GRAPHICS_ENGINE_NODE_HPP