#include "object.h"
#include "raylib.h"
#include <stdio.h>

struct Sphere initSphere(Vector3 position, float radius, Color color){

  struct Sphere sphere = {

    .position = position,
    .velocity = {0,0,0},
    .acceleration = {0,0,0},
    .color = color,
    .radius = radius,

  };

  return sphere;
}

void drawSphereObject(const struct Sphere *sphere){
  
  DrawSphere(sphere->position, sphere->radius, sphere->color);

}

void updateSphere(struct Sphere *sphere, float dt){
  sphere->velocity.x += sphere->acceleration.x*dt;
  sphere->velocity.y += sphere->acceleration.y*dt;
  sphere->velocity.z += sphere->acceleration.z*dt;

  sphere->position.x += sphere->velocity.x*dt;
  sphere->position.y += sphere->velocity.y*dt;
  sphere->position.z += sphere->velocity.z*dt;

}

void handleInput(struct Sphere *sphere) {

}
