#include <iostream>

#include "includes/systems/renderers/text_renderer/displays/console_display.hpp"

ConsoleDisplay::ConsoleDisplay(size_t height, size_t width) : TextDisplay(height, width)
{}

void ConsoleDisplay::draw(std::unique_ptr<TextRenderFragment> renderedImage)
{
    for (size_t i = 0; i < renderedImage->height; ++i)
    {
        for (size_t j = 0; j < renderedImage->width; ++j)
        {
            auto index = (i * renderedImage->width) + j;
            std::cout << renderedImage->content[index];
        }

        std::cout << '\n';
    }
}