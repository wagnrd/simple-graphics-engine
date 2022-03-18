#include "includes/engine.hpp"
#include "includes/node.hpp"

Engine* Engine::get()
{
    static Engine* instance{new Engine};

    return instance;
}

void Engine::run()
{
    if (!mScene)
        throw std::runtime_error("No scene set. Nothing to render.");

    mLastFrameTime = steadyClock::now();

    while (shouldRun)
    {
        auto startFrameTime = steadyClock::now();
        auto deltaTime = calculate_frame_delta_time(startFrameTime);

        auto fps = 1.f / deltaTime;
        std::cout << "### Frame start (fps: " << fps << ") ###" << std::endl;

        process_node_updates(deltaTime);
        process_systems();

        std::cout << "### Frame end ###" << std::endl;

        control_frame_rate(startFrameTime);
        mLastFrameTime = startFrameTime;
    }
}

void Engine::exit()
{
    shouldRun = false;
}

void Engine::process_node_updates(float deltaTime)
{
    mScene->update(deltaTime);
}

void Engine::process_systems()
{
    for (auto[_, system]: mSystems)
        mThreadPool.push_task([system = system] { system->process(); });

    mThreadPool.wait_for_tasks();
}

std::shared_ptr<Node> Engine::copy_node(const std::shared_ptr<Node>& node)
{
    auto nodeCopy = std::make_shared<Node>(*node);
    nodeCopy->remove_all_children();

    for (size_t i = 0; i < node->children_count(); ++i)
    {
        auto childCopy = copy_node(node->find_child(i).value());
        nodeCopy->add_child(childCopy);
    }

    return nodeCopy;
}

void Engine::control_frame_rate(steadyClock::time_point startFrameTime) const
{
    auto frameDuration = steadyClock::now() - startFrameTime;
    std::chrono::milliseconds minFrameDuration{static_cast<size_t>((1.0f / mFpsLimit) * 1000.f)};

    if (frameDuration < minFrameDuration)
    {
        auto sleepDuration = minFrameDuration - frameDuration;
        std::this_thread::sleep_for(sleepDuration);
    }
}

float Engine::calculate_frame_delta_time(steadyClock::time_point startFrameTime)
{
    auto frameDuration = startFrameTime - mLastFrameTime;
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(frameDuration).count();

    return 0.001f * static_cast<float>(milliseconds);
}

/**********************
* Getters and Setters *
***********************/
std::shared_ptr<Node> Engine::scene() const
{
    return Engine::mScene;
}

void Engine::set_scene(const std::shared_ptr<Node>& scene)
{
    mScene = scene;
}

size_t Engine::fps_limit() const
{
    return mFpsLimit;
}

void Engine::set_fps_limit(size_t fpsLimit)
{
    mFpsLimit = fpsLimit;
}