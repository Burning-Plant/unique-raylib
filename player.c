#include "header.h"
#define SPEED 0.05
#define FRICTION 0.98

void populatePlayer(Player *instance,Camera * camera) {
	*instance = (Player){ 0 };
	instance->camera = camera;	
}

void UpdatePlayer(Player *self, InputState input) {
	//self->direction;

	self->velocity = Vector3Add(self->velocity, Vector3Scale(input.direction,SPEED));
	self->position = Vector3Add(self->position,self->velocity);
	self->velocity = Vector3Scale(self->velocity,FRICTION);
	self->camera->position = self->position;

	//printf("xyz : %f, %f, %f\n",input.direction.x,input.direction.y,input.direction.z);
	
	//bullshit maths to update facing direction
}

void DrawHUD(Player *self) {
	DrawText(TextFormat("position: %f,%f,%f",self->position.x,self->position.y,self->position.z), 15, 25, 10, BLACK);
	DrawText(TextFormat("vel: %f,%f,%f",self->velocity.x,self->velocity.y,self->velocity.z), 25, 35, 10, BLACK);	
	DrawText(TextFormat("dir: %f,%f,%f",self->direction.x,self->direction,self->direction.z), 35, 45, 10, BLACK);	
}
