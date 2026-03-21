#include <raylib.h>
#include <raymath.h>

#include "camera.h"
#include "object.h"
#include "physics.h"

#define SCREENWIDTH 800
#define SCREENHEIGHT 450

#define FPS 60

int main(void) {

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib test");

  SetTargetFPS(FPS);
  
  Camera3D camera = initCamera();

  struct Sphere sphere = initSphere((Vector3){0,10,0}, 1, RED);
  sphere.velocity = (Vector3){0,1,0};

  while (!WindowShouldClose()) {

    float dt = GetFrameTime();
    handleCamera(&camera);
    sphere.velocity = (Vector3){0,0,0};
    applyGravity(&sphere);
    updateSphere(&sphere, dt);
  
    BeginDrawing();
    ClearBackground(GRAY);
    BeginMode3D(camera);
    drawSphereObject(&sphere);
    DrawGrid(10, 1.0f);
   
    EndMode3D();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
