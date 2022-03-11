#ifndef SIMPLE_GRAPHICS_ENGINE_SYSTEM_HPP
#define SIMPLE_GRAPHICS_ENGINE_SYSTEM_HPP

#include "node.hpp"

class System {
public:
    virtual void process() = 0;

    virtual ~System() = default;
};

#endif //SIMPLE_GRAPHICS_ENGINE_SYSTEM_HPP