#include <raylib.h>
#include <raymath.h>

#include "camera.h"
#include "object.h"

#define SCREENWIDTH 800
#define SCREENHEIGHT 450

void handleInput(struct Object *);

int main(void) {

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib test");

  SetTargetFPS(60);

  Camera3D camera = initCamera();

  while (!WindowShouldClose()) {

    handleCamera(&camera);

    BeginDrawing();
    ClearBackground(GRAY);
    BeginMode3D(camera);

    DrawSphere((Vector3){0.0f, 1.0f, 0.0f}, 1, RED);
    DrawGrid(10, 1.0f);
   
    EndMode3D();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
