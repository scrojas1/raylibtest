#pragma once
#include <raylib.h>
#include <raymath.h>

struct Sphere {
  Vector3 position;
  Vector3 velocity;
  Vector3 acceleration;
  float radius;
  Color color;
};

struct Sphere initSphere(Vector3 position, float radius, Color color);

void drawSphereObject(const struct Sphere *sphere);
void handleInput(struct Sphere *sphere);
