#ifndef SIMPLE_GRAPHICS_ENGINE_TEXT_RENDERER_HPP
#define SIMPLE_GRAPHICS_ENGINE_TEXT_RENDERER_HPP

#include "includes/systems/null_renderer.hpp"
#include "text_screen.hpp"
#include "includes/components/camera.hpp"

class TextRenderer: public System {
protected:
    std::unordered_multimap<std::shared_ptr<Camera>, std::shared_ptr<TextScreen>> mCameras;

public:
    void process() override;

    template<class T, typename... Args>
    std::shared_ptr<T> emplace_screen(std::shared_ptr<Camera> camera, Args... args)
    {
        auto screen = std::make_shared<T>(args...);
        mCameras.insert({camera, screen});
    }
};

#endif //SIMPLE_GRAPHICS_ENGINE_TEXT_RENDERER_HPP