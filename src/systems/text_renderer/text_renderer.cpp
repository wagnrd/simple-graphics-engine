
#include "includes/systems/text_renderer/text_renderer.hpp"

void TextRenderer::process()
{
    for (const auto&[camera, screens]: mCameras)
    {
        auto rootNode = camera->renderable_node_tree();
        auto renderedImage = render(rootNode);

        for (const auto& screen: screens)
            screen->draw(renderedImage);
    }
}

std::vector<char> TextRenderer::render(std::shared_ptr<Node> root)
{
    return {};
}