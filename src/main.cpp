#include <chrono>

#include "raylib.h"
#include "scene_tree.hpp"
#include "utils.hpp"
#include "temp_data.hpp"
#include "rendering_server.hpp"

using namespace rre;

void draw_routine() {

	ClearBackground(GRAY);

	//[NodeA,NodeB,NodeC]
	//buffer.commit();

	EndDrawing();
}

SceneTree* tree = nullptr;

int main(int argc, char* argv[])
{
	// Initialization
	//--------------------------------------------------------------------------------------



	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
	InitWindow(screenWidth, screenHeight, "Red Robot Engine");
	SetTargetFPS(60);


	// auto delta = std::chrono::high_resolution_clock::now();


	InputEvent* input_event = new InputEvent();

	tree = new SceneTree();
	
	ClearBackground(GRAY);
	


	while(!WindowShouldClose()) {
		TIMER_START();

		BeginDrawing();

		input_event->check_update(tree);


		if (IsKeyDown(KEY_SPACE)) {

			tree->redraw();

		}


		EndDrawing();

		TIMER_END(std::string("Loop"));

	}

	
	// UnloadRenderTexture(tex);
	delete tree;
	

	CloseWindow();        // Close window and OpenGL context

	return 0;
}
