#include "header.h"
#define SPEED 0.05
#define FRICTION 0.98
#define HORIZANTAL_SENSITIVITY -0.0075
#define VERTICAL_SENSITIVITY 0.01

void populatePlayer(Player *instance,Camera * camera) {
	*instance = (Player){ 0 };
	instance->camera = camera;

	instance->direction = (Vector3){ 0, 0, 1};

	instance->headOffset = (Vector3){
		0,
		1,
		0,
	};
}

void UpdatePlayer(Player *self, InputState input) {
	const Vector3 constUp = (Vector3){
		0,
		1,
		0,
	};

	Vector3 axisPitch = Vector3CrossProduct(constUp,self->direction);
	float yawDelta = input.lookDelta.x * HORIZANTAL_SENSITIVITY;
	float pitchDelta = input.lookDelta.y * VERTICAL_SENSITIVITY;

	self->direction = Vector3RotateByAxisAngle(self->direction,axisPitch,pitchDelta);
	self->direction = Vector3RotateByAxisAngle(self->direction,constUp,yawDelta);

	self->velocity = Vector3Add(self->velocity, Vector3Scale(input.direction,SPEED)); //TODO: align input direction to charecter yaw rotation, calculate from self->direction
	self->position = Vector3Add(self->position,self->velocity);
	self->velocity = Vector3Scale(self->velocity,FRICTION);
	self->camera->position = self->position;


	self->camera->position = Vector3Add(self->position,self->headOffset);
	self->camera->target = Vector3Add(self->camera->position,self->direction);
	//printf("xyz : %f, %f, %f\n",input.direction.x,input.direction.y,input.direction.z);
	
	//bullshit maths to update facing direction
}

void DrawHUD(Player *self) {
	DrawText(TextFormat("position: %f,%f,%f",self->position.x,self->position.y,self->position.z), 15, 25, 10, BLACK);
	DrawText(TextFormat("vel: %f,%f,%f",self->velocity.x,self->velocity.y,self->velocity.z), 25, 35, 10, BLACK);	
	DrawText(TextFormat("dir: %f,%f,%f",self->direction.x,self->direction,self->direction.z), 35, 45, 10, BLACK);	
}
