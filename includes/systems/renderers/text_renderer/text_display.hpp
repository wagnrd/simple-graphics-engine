#ifndef SIMPLE_GRAPHICS_ENGINE_TEXT_DISPLAY_HPP
#define SIMPLE_GRAPHICS_ENGINE_TEXT_DISPLAY_HPP

#include <vector>
#include <memory>

#include "text_render_fragment.hpp"

class TextDisplay {
protected:
    size_t height;
    size_t width;

public:
    TextDisplay(size_t height, size_t width) : height(height), width(width)
    {}

    virtual void draw(std::unique_ptr<TextRenderFragment> renderedImage) = 0;

    virtual ~TextDisplay() = default;
};

#endif //SIMPLE_GRAPHICS_ENGINE_TEXT_DISPLAY_HPP