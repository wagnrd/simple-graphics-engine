#include <glm/ext/matrix_transform.hpp>

#include "includes/components/renderer/renderables/line.hpp"

Line::Line(const glm::vec4& color) : mColor(color)
{}

std::unique_ptr<RenderFragment>
Line::render(const std::shared_ptr<Transform>& transform, const glm::vec2& aspectRatio) const
{
    /*
    glm::vec2 a{0, -transform->scale.y};
    glm::vec2 b{0, transform->scale.y};
     */

    auto renderFragment = std::make_unique<RenderFragment>(1, transform->scale.y * 2);

    for (size_t i = 0; i < (size_t) glm::ceil(transform->scale.y * 2); ++i)
        renderFragment->content[i] = glm::vec4{255, 255, 255, 1};

    return renderFragment;
}

void Line::set_color(glm::vec4 color)
{
    mColor = color;
}

glm::vec4 Line::color() const
{
    return mColor;
}