#ifndef SIMPLE_GRAPHICS_ENGINE_CONSOLE_TEXT_SCREEN_HPP
#define SIMPLE_GRAPHICS_ENGINE_CONSOLE_TEXT_SCREEN_HPP

#include "includes/systems/text_renderer/text_screen.hpp"

class ConsoleTextScreen: public TextScreen {
public:
    void draw(std::vector<char> renderedImage) override;
};

#endif //SIMPLE_GRAPHICS_ENGINE_CONSOLE_TEXT_SCREEN_HPP