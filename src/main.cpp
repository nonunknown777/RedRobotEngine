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

#include "imgui.h"
#include "rlImGui.h"

#include "nodes/tree.hpp"
#include "utils.hpp"

#include "temp_data.hpp"

int main(int argc, char* argv[])
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = WINDOW_SIZE.x;
	int screenHeight = WINDOW_SIZE.y;

	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
	InitWindow(screenWidth, screenHeight, "Z-Engine");
	SetTargetFPS(60);
	rlImGuiSetup(true);

	SceneTree tree = SceneTree();

	auto delta_start = std::chrono::high_resolution_clock::now();

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Get the current time inside the loop
        auto delta_current = std::chrono::high_resolution_clock::now();

		 // Calculate delta time in seconds
        std::chrono::duration<float> delta_seconds = delta_current - delta_start;
        float delta = delta_seconds.count();
		// Update start time for the next iteration
        delta_start = delta_current;

        
		BeginDrawing();
		ClearBackground(DARKGRAY);

		// start ImGui Content
		rlImGuiBegin();

		
		tree.update(delta);
		

		// end ImGui Content
		rlImGuiEnd();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}
	rlImGuiShutdown();

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}