#include "common.hpp"

namespace rre {


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
	InitWindow(screenWidth, screenHeight, "Z-Engine");
	SetTargetFPS(60);


	// auto delta_start = std::chrono::high_resolution_clock::now();

	// tree = new SceneTree();



	// Main game loop
	// while (!WindowShouldClose())    // Detect window close button or ESC key
	// {
	// 	TIMER_START();
	// 	// Calculate delta time in seconds
    //     auto delta_current = std::chrono::high_resolution_clock::now();
    //     std::chrono::duration<float> delta_seconds = delta_current - delta_start;
    //     float delta = delta_seconds.count();

	ClearBackground(GRAY);

	// 	// if (tree != nullptr)
	// 	// 	tree->update(delta);
		
	// 	// if (IsKeyPressed(KEY_A)) {
	// 	// 	tree->root->get_child(0)->visible = false;
	// 	// }

	
    //     delta_start = delta_current;

	// 	// DrawText(TextFormat("FPS: %03i",GetFPS()),720,100,16,GREEN);
	// 	EndDrawing();

	// 	TIMER_END("main loop");
	// }
	DrawRectangle(0,0,100,200,RED);
	EndDrawing();

	tree = new SceneTree();
	

	while(!WindowShouldClose()){

		if (IsKeyPressed(KEY_ESCAPE)) {
			break;
		}
	}

	delete tree;
	CloseWindow();        // Close window and OpenGL context

	return 0;
}

}
