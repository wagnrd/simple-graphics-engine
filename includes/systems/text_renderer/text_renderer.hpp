#ifndef SIMPLE_GRAPHICS_ENGINE_TEXT_RENDERER_HPP
#define SIMPLE_GRAPHICS_ENGINE_TEXT_RENDERER_HPP

#include <vector>

#include "includes/systems/null_renderer.hpp"
#include "text_screen.hpp"
#include "includes/components/camera.hpp"

class TextRenderer: public System {
protected:
    std::unordered_map<std::shared_ptr<Camera>, std::deque<std::shared_ptr<TextScreen>>> mCameras;

public:
    void process() override;

    template<class T, typename... Args>
    std::shared_ptr<T> emplace_screen(const std::shared_ptr<Camera>& camera, Args... args)
    {
        auto screen = std::make_shared<T>(args...);
        auto it = mCameras.find(camera);

        if (it == mCameras.end())
            mCameras[camera] = std::deque<std::shared_ptr<TextScreen>>();

        mCameras[camera].push_back(std::static_pointer_cast<TextScreen>(screen));

        return screen;
    }

private:
    std::vector<char> render(std::shared_ptr<Node> node);
};

#endif //SIMPLE_GRAPHICS_ENGINE_TEXT_RENDERER_HPP