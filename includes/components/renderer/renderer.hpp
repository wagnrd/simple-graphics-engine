#ifndef SIMPLE_GRAPHICS_ENGINE_RENDERER_HPP
#define SIMPLE_GRAPHICS_ENGINE_RENDERER_HPP

#include "includes/systems/renderers/render_fragment.hpp"
#include "includes/component.hpp"
#include "renderable.hpp"

class Renderer: public Component {

    std::shared_ptr<Transform> mTransform;
    std::shared_ptr<Renderable> mRenderable{};

public:
    Renderer(const std::shared_ptr<Renderable>& mRenderable);

    void start() override;
    [[nodiscard]] std::unique_ptr<RenderFragment> render(glm::vec2 aspectRatio) const;

    void set_renderable(const std::shared_ptr<Renderable>& renderable);
    [[nodiscard]] std::shared_ptr<Renderable> renderable() const;
};

#endif //SIMPLE_GRAPHICS_ENGINE_RENDERER_HPP