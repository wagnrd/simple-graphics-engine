#include "includes/systems/text_renderer/text_renderer.hpp"

void TextRenderer::process()
{
    for (auto[camera, screen]: mCameras)
    {
        auto rootNode = camera->visible_node_tree();
    }
}