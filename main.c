#include "header.h"
//#define SMEAR

static Player player;

int main(void) {
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "unique game");

	static Camera camera = { 0 };
	camera.fovy = 100.;
	camera.projection = CAMERA_PERSPECTIVE;
	camera.position = (Vector3){
		0,
		0,
		0
	};
	camera.target = (Vector3){
		0,
		0,
		0
	};
	camera.up = (Vector3){
		0,
		1,
		0,
	};

	populatePlayer(&player,&camera);
	
	DisableCursor();
	SetTargetFPS(60);
	//ClearBackground(RAYWHITE);

	while (!WindowShouldClose())
		{
			InputState input = DetectInput();
			UpdatePlayer(&player,input);	

			BeginDrawing();
				#if !defined SMEAR
					ClearBackground(RAYWHITE); // remove this for a cool smear
				#endif

				BeginMode3D(camera);
					DrawGrid(100, 2.);
					//DrawLevel();
					DrawCube((Vector3){0,0,0}, 2., 2., 2., BLUE); 
					//DrawCubeV((Vector3){-2,-2,2}, (Vector3){4,4,4}, RED);  
			
				EndMode3D();

				DrawText("test", 15, 15, 10, BLACK);
				DrawHUD(&player);
				//DrawTexture(player.heldItem->texture, screenWidth/2, screenHeight/2, RED);
			EndDrawing();
		}
	CloseWindow();

	return 0;
}
