#ifndef SIMPLE_GRAPHICS_ENGINE_TEXT_RENDERER_HPP
#define SIMPLE_GRAPHICS_ENGINE_TEXT_RENDERER_HPP

#include <unordered_set>

#include "text_display.hpp"
#include "text_render_fragment.hpp"
#include "includes/systems/renderers/null_renderer.hpp"
#include "includes/components/camera.hpp"

class TextRenderer: public System {
protected:
    std::unordered_map<std::shared_ptr<Camera>, std::unordered_set<std::shared_ptr<TextDisplay>>> mCameras;

public:
    void process() override;

    void add_display(const std::shared_ptr<Camera>& camera, const std::shared_ptr<TextDisplay>& display);
    void swap_camera(const std::shared_ptr<Camera>& oldCamera, const std::shared_ptr<Camera>& newCamera);

private:
    [[nodiscard]] std::unique_ptr<TextRenderFragment> render(const std::shared_ptr<Node>& node) const;
};

#endif //SIMPLE_GRAPHICS_ENGINE_TEXT_RENDERER_HPP