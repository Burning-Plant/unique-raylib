#include "header.h"

InputState DetectInput() {
	InputState input = { 0 };
	
	input.direction = (Vector3){
		IsKeyDown(KEY_A)-IsKeyDown(KEY_D),
		IsKeyDown(KEY_SPACE)-IsKeyDown(KEY_LEFT_CONTROL),
		IsKeyDown(KEY_W)-IsKeyDown(KEY_S),
	};

	input.lookDelta = GetMouseDelta();

	input.crouch = (IsKeyPressed(KEY_LEFT_CONTROL) || IsKeyPressed(KEY_C));

	input.jump = IsKeyPressed(KEY_SPACE);

	input.use = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
	input.use_held = IsMouseButtonDown(MOUSE_BUTTON_LEFT);

	input.altUse = IsMouseButtonPressed(MOUSE_BUTTON_RIGHT);
	input.altUse_held = IsMouseButtonDown(MOUSE_BUTTON_RIGHT);

	/*for(int key = GetKeyPressed(); key != 0; key = GetKeyPressed()) {
		printf("%s key was pressed (thats %i)\n",GetKeyName(key), key);
	}*/
	
	return input;
};
