#include <raylib.h>
#include <raymath.h>

#include "camera.h"
#include "object.h"

#define SCREENWIDTH 800
#define SCREENHEIGHT 450


int main(void) {

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib test");

  SetTargetFPS(60);

  Camera3D camera = initCamera();

  struct Sphere sphere = initSphere((Vector3){0,1,0}, 1, GREEN);

  while (!WindowShouldClose()) {

    handleCamera(&camera);

    BeginDrawing();
    ClearBackground(GRAY);
    BeginMode3D(camera);
    DrawSphere(sphere.position, sphere.radius, sphere.color);
    DrawGrid(10, 1.0f);
   
    EndMode3D();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
