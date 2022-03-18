#ifndef SIMPLE_GRAPHICS_ENGINE_RENDER_FRAGMENT_HPP
#define SIMPLE_GRAPHICS_ENGINE_RENDER_FRAGMENT_HPP

#include <vector>
#include <glm/vec4.hpp>

class RenderFragment {
public:
    size_t width{};
    size_t height{};
    std::vector<glm::vec4> content{};

    RenderFragment() = default;

    RenderFragment(size_t width, size_t height)
            : height(height),
              width(width),
              content(width * height)
    {}
};

#endif //SIMPLE_GRAPHICS_ENGINE_RENDER_FRAGMENT_HPP