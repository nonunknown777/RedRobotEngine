#include <chrono>

#include "raylib.h"
#include "scene_tree.hpp"
#include "utils.hpp"
#include "temp_data.hpp"

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

	auto test = [](Node* current){
        // std::cout << "iterated at: " << current->get_name() << "\n";
    };

	auto delta = std::chrono::high_resolution_clock::now();

	tree = new SceneTree();
	

	while(!WindowShouldClose()) {
		TIMER_START();
		
		ClearBackground(GRAY);

		tree->traverse_bottom_top(test);


		EndDrawing();



		TIMER_END(std::string("Loop"));



	}

	delete tree;
	CloseWindow();        // Close window and OpenGL context

	return 0;
}
