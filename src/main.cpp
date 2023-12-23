/*******************************************************************************************
*
*   raylib-extras [ImGui] example - Simple Integration
*
*	This is a simple ImGui Integration
*	It is done using C++ but with C style code
*	It can be done in C as well if you use the C ImGui wrapper
*	https://github.com/cimgui/cimgui
*
*   Copyright (c) 2021 Jeffery Myers
*
********************************************************************************************/

#include "raylib.h"
#include "raymath.h"

#include "nodes/tree.hpp"
#include "utils.hpp"

#include "temp_data.hpp"

#include <chrono>

int main(int argc, char* argv[])
{
	// Initialization
	//--------------------------------------------------------------------------------------


	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
	InitWindow(screenWidth, screenHeight, "Z-Engine");
	SetTargetFPS(60);

	SceneTree tree = SceneTree();

	auto delta_start = std::chrono::high_resolution_clock::now();

	// bool window_created = false;

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Calculate delta time in seconds
        auto delta_current = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> delta_seconds = delta_current - delta_start;
        float delta = delta_seconds.count();

		ClearBackground(RAYWHITE);

		tree.update(delta);

	
        delta_start = delta_current;
		EndDrawing();
	}
	

	CloseWindow();        // Close window and OpenGL context

	return 0;
}

