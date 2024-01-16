#pragma once

#include "canvas_item.hpp"
#include "raylib.h"

namespace rre {

    struct DrawBuffer {
        std::vector<CanvasItem*> buffer;
        RenderTexture render;

        DrawBuffer() {
            buffer = std::vector<CanvasItem*>();
            render = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
        }

        ~DrawBuffer() {
            UnloadRenderTexture(render);
        }
    };

    class RenderingServer {
        private:
            std::vector<DrawBuffer*> draw_buffers;

            RenderingServer(const RenderingServer&) = delete;
            RenderingServer& operator=(const RenderingServer&) = delete;

        public:
            RenderingServer();
            ~RenderingServer();

            static RenderingServer& get_singleton() {
                static RenderingServer instance;
                return instance;
            }



            void update();
            void register_into_buffer(size_t index, CanvasItem* canvas_item);

    };
}