#ifndef SIMPLE_GRAPHICS_ENGINE_CONSOLE_DISPLAY_HPP
#define SIMPLE_GRAPHICS_ENGINE_CONSOLE_DISPLAY_HPP

#include "includes/systems/renderers/text_renderer/text_display.hpp"

class ConsoleDisplay: public TextDisplay {
public:
    ConsoleDisplay(size_t height, size_t width);

    void draw(std::unique_ptr<TextRenderFragment> renderedImage) override;
};

#endif //SIMPLE_GRAPHICS_ENGINE_CONSOLE_DISPLAY_HPP