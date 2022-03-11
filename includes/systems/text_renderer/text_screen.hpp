#ifndef SIMPLE_GRAPHICS_ENGINE_TEXT_SCREEN_HPP
#define SIMPLE_GRAPHICS_ENGINE_TEXT_SCREEN_HPP

#include <vector>

class TextScreen {
public:
    virtual void draw(std::vector<char> renderedImage) = 0;

    virtual ~TextScreen() = default;
};

#endif //SIMPLE_GRAPHICS_ENGINE_TEXT_SCREEN_HPP