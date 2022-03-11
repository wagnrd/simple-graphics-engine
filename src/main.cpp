#include "includes/components/transform.hpp"
#include "includes/components/mover.hpp"
#include "includes/engine.hpp"
#include "includes/systems/text_renderer/text_renderer.hpp"
#include "includes/systems/text_renderer/displays//console_display.hpp"

int main()
{
    auto textRenderer = Engine::get()->enable_system<TextRenderer>();

    auto scene = Engine::get()->emplace_scene();
    auto camera = scene->emplace_component<Camera>();

    auto npc = scene->emplace_child("npc");
    auto transform = npc->emplace_component<Transform>(glm::vec2(1, 2));
    npc->emplace_component<Mover>(glm::vec2(10, 10));

    textRenderer->emplace_display<ConsoleDisplay>(camera);

    Engine::get()->run();
}