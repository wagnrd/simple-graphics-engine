#ifndef SIMPLE_GRAPHICS_ENGINE_ENGINE_HPP
#define SIMPLE_GRAPHICS_ENGINE_ENGINE_HPP

#include <memory>
#include <utility>
#include <chrono>
#include <unordered_map>

#include "libs/thread-pool/thread_pool.hpp"
#include "includes/system.hpp"

class Node;

class Engine {

    using steadyClock = std::chrono::steady_clock;

    bool shouldRun{true};
    thread_pool mThreadPool{};
    steadyClock::time_point mLastFrameTime{};
    std::unordered_map<const char*, std::shared_ptr<System>> mSystems{};

    std::shared_ptr<Node> mScene{};
    size_t mFpsLimit;

public:
    static Engine* get();

    void run();
    void exit();

    template<class T, typename... Args>
    std::shared_ptr<T> emplace_system(Args... args)
    {
        auto typeName = typeid(T).name();
        auto it = mSystems.find(typeName);

        if (it != mSystems.end())
            return std::dynamic_pointer_cast<T>(it->second);

        auto system = std::make_shared<T>(args...);
        mSystems.insert({typeName, system});

        return system;
    }

    template<class T>
    void remove_system()
    {
        auto typeName = typeid(T).name();
        auto it = mSystems.find(typeName);

        if (it == mSystems.end())
            return;

        mSystems.erase(it);
    }

    template<class T>
    [[nodiscard]] std::optional<std::shared_ptr<T>> find_system() const
    {
        auto typeName = typeid(T).name();
        auto it = mSystems.find(typeName);

        if (it == mSystems.end())
            return {};

        return it->second;
    }

    // Getters and Setters
    [[nodiscard]] std::shared_ptr<Node> scene() const;
    void set_scene(const std::shared_ptr<Node>& scene);
    [[nodiscard]] size_t fps_limit() const;
    void set_fps_limit(size_t fpsLimit);

private:
    void process_node_updates(float deltaTime);
    void process_systems();
    void control_frame_rate(steadyClock::time_point startFrameTime) const;
    float calculate_frame_delta_time(steadyClock::time_point startFrameTime);

    std::shared_ptr<Node> copy_node(const std::shared_ptr<Node>& node);
};

#endif //SIMPLE_GRAPHICS_ENGINE_ENGINE_HPP