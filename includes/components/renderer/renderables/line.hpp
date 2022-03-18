#ifndef SIMPLE_GRAPHICS_ENGINE_LINE_HPP
#define SIMPLE_GRAPHICS_ENGINE_LINE_HPP

#include <memory>

#include "includes/components/renderer/renderable.hpp"
#include "includes/components/transform.hpp"

class Line: public Renderable {

    glm::vec4 mColor{};

public:
    Line() = default;
    explicit Line(const glm::vec4& color);
    [[nodiscard]] std::unique_ptr<RenderFragment> render(const std::shared_ptr<Transform>& transform,
                                                         const glm::vec2& aspectRatio) const override;

    void set_color(glm::vec4 color);
    [[nodiscard]] glm::vec4 color() const;
};

#endif //SIMPLE_GRAPHICS_ENGINE_LINE_HPP