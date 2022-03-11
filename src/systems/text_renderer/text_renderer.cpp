
#include "includes/systems/text_renderer/text_renderer.hpp"

void TextRenderer::process()
{
    for (const auto&[camera, displays]: mCameras)
    {
        auto rootNode = camera->renderable_node_tree();
        auto renderedImage = render(rootNode);

        for (const auto& display: displays)
            display->draw(renderedImage);
    }
}

std::vector<char> TextRenderer::render(std::shared_ptr<Node> root)
{
    return {};
}