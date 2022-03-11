#include "includes/engine.hpp"
#include "includes/node.hpp"

Engine* Engine::get()
{
    static Engine* instance{new Engine};

    return instance;
}

std::shared_ptr<Node> Engine::emplace_scene()
{
    mScene = std::make_shared<Node>();
    return mScene;
}

void Engine::set_scene(std::shared_ptr<Node> scene)
{
    mScene = std::move(scene);
}

void Engine::run()
{
    if (!mScene)
        throw std::runtime_error("No scene set. Nothing to render.");

    mLastFrameTime = steadyClock::now();

    while (true)
    {
        process_node_updates();
        process_node_post_updates();
        process_systems();
    }
}

void Engine::process_node_updates()
{
    auto now = steadyClock::now();
    auto frameDuration = now - Engine::mLastFrameTime;
    mLastFrameTime = now;
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(frameDuration).count();
    float deltaTime = 0.001f * static_cast<float>(milliseconds);

    mScene->update(deltaTime);
}

void Engine::process_node_post_updates()
{
    threadPool.wait_for_tasks();
    mScene->post_update();
}

void Engine::process_systems()
{
    threadPool.wait_for_tasks();

    for (auto[_, system]: mSystems)
        threadPool.push_task([system = system] { system->process(); });
}

/**********
* Getters *
***********/
std::shared_ptr<Node> Engine::scene()
{
    return Engine::mScene;
}