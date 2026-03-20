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

void handleInput(struct Sphere *sphere) {

}
