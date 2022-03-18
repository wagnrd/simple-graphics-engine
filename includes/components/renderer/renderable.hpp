#ifndef SIMPLE_GRAPHICS_ENGINE_RENDERABLE_HPP
#define SIMPLE_GRAPHICS_ENGINE_RENDERABLE_HPP

#include "includes/systems/renderers/render_fragment.hpp"
#include "includes/components/transform.hpp"

class Renderable {
public:
    [[nodiscard]] virtual std::unique_ptr<RenderFragment> render(const std::shared_ptr<Transform>& transform,
                                                                 const glm::vec2& aspectRatio) const = 0;

    virtual ~Renderable() = default;
};

#endif //SIMPLE_GRAPHICS_ENGINE_RENDERABLE_HPP