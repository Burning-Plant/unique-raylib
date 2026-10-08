#include "header.h"

enum anim {
	BASE, THROW
} anim;

typedef struct Player {
	Vector3 headOffset;

	Vector3 position;
	Vector3 velocity;
	Vector3 direction;
	
	Camera *camera;
	//Item *heldItem;

	enum anim state;
	int frame;
} Player;
