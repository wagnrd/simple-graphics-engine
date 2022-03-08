#ifndef SIMPLE_GRAPHICS_ENGINE_NULL_RENDERER_HPP
#define SIMPLE_GRAPHICS_ENGINE_NULL_RENDERER_HPP

#include "includes/system.hpp"

class NullRenderer: public System {
public:
    void process() override
    {}
};

#endif //SIMPLE_GRAPHICS_ENGINE_NULL_RENDERER_HPP