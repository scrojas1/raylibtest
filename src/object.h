#pragma once
#include <raylib.h>
#include <raymath.h>

struct Object {
  float x;
  float y;
  int direction;
  float acceleration;
  const int radius;
};

struct Object initBall(int posX, int posY, int radius);

void handleInput(struct Object *obj);
