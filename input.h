#include "header.h"

typedef struct InputState {
	Vector3 direction;
	Vector2 lookDelta;
	bool crouch;
	bool jump;
	bool use;
	bool use_held;
	bool altUse;
	bool altUse_held;
} InputState; //abstract away from specific keys


