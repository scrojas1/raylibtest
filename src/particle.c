#include "particle.h"
#include <stdio.h>

struct Object initBall(int posX, int posY, int radius) {

  struct Object ball = {
      .x = posX,
      .y = posY,
      .direction = 1,
      .acceleration = 1,
      .radius = radius,
  };

  return ball;
}

void handleInput(struct Object *obj) {

  if (IsKeyDown(KEY_UP)) {
    obj->acceleration += 0.1;
    printf("Acceleration: %f\n", obj->acceleration);
  } else if (IsKeyDown(KEY_DOWN)) {
    obj->acceleration -= 0.1;
    printf("Acceleration: %f\n", obj->acceleration);
  }
}
