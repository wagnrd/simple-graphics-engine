#ifndef SIMPLE_GRAPHICS_ENGINE_CONSOLE_DISPLAY_HPP
#define SIMPLE_GRAPHICS_ENGINE_CONSOLE_DISPLAY_HPP

#include "includes/systems/text_renderer/text_screen.hpp"

class ConsoleDisplay: public TextDisplay {
public:
    void draw(std::vector<char> renderedImage) override;
};

#endif //SIMPLE_GRAPHICS_ENGINE_CONSOLE_DISPLAY_HPP