#ifndef SIMPLE_GRAPHICS_ENGINE_ENGINE_HPP
#define SIMPLE_GRAPHICS_ENGINE_ENGINE_HPP

#include <memory>
#include <utility>
#include <chrono>
#include <unordered_map>
#include "system.hpp"
#include "includes/utils/thread-pool/thread_pool.hpp"

class Node;

class Engine {

    using steadyClock = std::chrono::steady_clock;

    thread_pool threadPool;
    steadyClock::time_point mLastFrameTime{};
    std::shared_ptr<Node> mScene{};
    std::unordered_map<const char*, System*> mSystems;

public:
    static Engine* get();

    std::shared_ptr<Node> emplace_scene();
    void set_scene(std::shared_ptr<Node> scene);
    [[noreturn]] void run();

    template<class T, typename... Args>
    T* enable_system(Args... args)
    {
        auto typeName = typeid(T).name();
        auto it = mSystems.find(typeName);

        if (it != mSystems.end())
            return dynamic_cast<T*>(it->second);

        auto system = new T(args...);
        mSystems.insert({typeName, system});

        return system;
    }

    template<class T>
    void disable_system()
    {
        auto typeName = typeid(T).name();
        auto it = mSystems.find(typeName);

        if (it == mSystems.end())
            return;

        delete it->second;
        mSystems.erase(it);
    }

    template<class T>
    [[nodiscard]] T* get_system()
    {
        auto typeName = typeid(T).name();
        auto it = mSystems.find(typeName);

        if (it == mSystems.end())
            throw std::runtime_error("System '" + std::string(typeName) + "' not found");

        return it->second;
    }

    // Getters
    [[nodiscard]] std::shared_ptr<Node> scene();

private:
    void process_node_updates();
    void process_systems();
    void process_node_post_updates();
};

#endif //SIMPLE_GRAPHICS_ENGINE_ENGINE_HPP