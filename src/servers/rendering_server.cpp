#pragma once

#include "rendering_server.hpp"

namespace rre {

RenderingServer::RenderingServer() {
    draw_buffers = std::vector<DrawBuffer*>();
    DrawBuffer* draw_buffer = new DrawBuffer();
    draw_buffers.push_back(draw_buffer);
}

RenderingServer::~RenderingServer() {
    DrawBuffer* b = draw_buffers[0];

    draw_buffers.clear();

    delete b;

}


// Will iterate over all canvas items in the current SceneTree registered ones
void RenderingServer::update() {
    size_t index = 0;

    #define render draw_buffers[index]->render
    #define buffer_index draw_buffers[index]
    #define buffer_size draw_buffers[index]->buffer.size()

    BeginTextureMode(render);

    ClearBackground(Color{255,255,0,0});

    for (int i = buffer_size-1; i > -1; i--)
    {
       draw_buffers[index]->buffer.at(i)->_draw();
    }

    EndTextureMode();

    DrawTextureRec(render.texture, Rectangle(0,0,render.texture.width,-render.texture.height),Vector2(0,0),WHITE);

    #undef render
    #undef buffer_index
    #undef buffer_size
}

//The user defines which index on the draw_buffers he wants to register this canvas layer
void RenderingServer::register_into_buffer(size_t index, CanvasItem* canvas_item) {
    draw_buffers[index]->buffer.push_back(canvas_item);
}


}
