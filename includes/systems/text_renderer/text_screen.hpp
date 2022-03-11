#ifndef SIMPLE_GRAPHICS_ENGINE_TEXT_SCREEN_HPP
#define SIMPLE_GRAPHICS_ENGINE_TEXT_SCREEN_HPP

#include <vector>

class TextDisplay {
public:
    virtual void draw(std::vector<char> renderedImage) = 0;

    virtual ~TextDisplay() = default;
};

#endif //SIMPLE_GRAPHICS_ENGINE_TEXT_SCREEN_HPP