#ifndef SIMPLE_GRAPHICS_ENGINE_TEXT_RENDER_FRAGMENT_HPP
#define SIMPLE_GRAPHICS_ENGINE_TEXT_RENDER_FRAGMENT_HPP

#include <vector>

class TextRenderFragment {
public:
    size_t width{};
    size_t height{};
    std::vector<char> content;

    TextRenderFragment() = default;

    TextRenderFragment(size_t width, size_t height)
            : width(width),
              height(height),
              content(width * height)
    {}
};

#endif //SIMPLE_GRAPHICS_ENGINE_TEXT_RENDER_FRAGMENT_HPP