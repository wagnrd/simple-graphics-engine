#include "includes/components/renderer/renderables/line.hpp"
#include <glm/gtx/rotate_vector.hpp>

Line::Line(const glm::vec4& color) : mColor(color)
{}

std::unique_ptr<RenderFragment>
Line::render(const std::shared_ptr<Transform>& transform, const glm::vec2& aspectRatio) const
{
    // rotate normalized vector
    auto a = glm::rotate(
            glm::vec2{0, 1},
            glm::radians(transform->rotation)
    );

    // scale to desired size
    a.x *= transform->scale.x;
    a.y *= transform->scale.y;

    // since the vector a is assumed to start at the 0-point b is just on the opposite side of the 0-point
    auto b = -a;

    // calculate slope
    auto m = (b.y - a.y) / (b.x - a.x);

    /*
    size_t minX{};
    size_t maxX{};
    size_t minY{};
    size_t maxY{};

    if (a.x < b.x)
    {
        minX = glm::floor(a.x * aspectRatio.x);
        maxX = glm::floor(b.x * aspectRatio.x);
    }
    else
    {
        minX = glm::floor(b.x * aspectRatio.x);
        maxX = glm::floor(a.x * aspectRatio.x);
    }

    if (a.y < b.y)
    {
        minY = glm::floor(a.y * aspectRatio.y);
        maxY = glm::floor(b.y * aspectRatio.y);
    }
    else
    {
        minY = glm::floor(b.y * aspectRatio.y);
        maxY = glm::floor(a.y * aspectRatio.y);
    }
     */

    // translate vectors (coordinates in this case) to positive values >= 0
    // the absolute of the vectors is always the offset it takes to get the negative values to >= 0
    // since they are mirrors of each other with the same length
    auto delta = glm::abs(a);
    a += delta;
    b += delta;

    auto renderFragment = std::make_unique<RenderFragment>(
            delta.x * 2,
            delta.y * 2
    );

    for (size_t x = minX; x < maxX; ++x)
    {
        auto y = static_cast<size_t>(glm::floor(m * x));
        auto index = static_cast<size_t>();
        renderFragment->content[index] = glm::vec4{255, 255, 255, 1};
    }

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