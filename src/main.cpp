#include "includes/engine.hpp"
#include "includes/components/camera.hpp"
#include "includes/components/transform.hpp"
#include "includes/components/mover.hpp"
#include "includes/systems/renderers/text_renderer/displays/console_display.hpp"
#include "includes/systems/renderers/text_renderer/text_renderer.hpp"
#include "includes/components/renderer/renderer.hpp"
#include "includes/components/renderer/renderables/line.hpp"

int main()
{
    auto npc = std::make_shared<Node>("npc");
    auto transform = npc->emplace_component<Transform>();
    transform->position = glm::vec2{1, 2};
    transform->scale = glm::vec2{1, 2};
    //npc->emplace_component<Mover>(glm::vec2(10, 10));
    npc->emplace_component<Renderer>(
            std::make_shared<Line>(glm::vec4(255, 255, 255, 1))
    );
    auto camera = npc->emplace_component<Camera>();
    Engine::get()->set_scene(npc);

    auto display = std::make_shared<ConsoleDisplay>(10, 10);
    Engine::get()->emplace_system<TextRenderer>()
                 ->add_display(camera, display);

    Engine::get()->set_fps_limit(1);
    Engine::get()->run();
}