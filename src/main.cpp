#include "includes/components/transform.hpp"
#include "includes/components/mover.hpp"
#include "includes/engine.hpp"
#include "includes/systems/null_renderer.hpp"
#include "includes/systems/text_renderer/text_renderer.hpp"

int main()
{
    Engine::get()->enable_system<TextRenderer>();
    auto scene = Engine::get()->emplace_scene();

    auto npc = scene->emplace_child("npc");
    auto transform = npc->emplace_component<Transform>(Position{1, 2});
    npc->emplace_component<Mover>(Position{10, 10});

    Engine::get()->run();
}