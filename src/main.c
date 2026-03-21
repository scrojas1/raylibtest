#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
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

  struct Sphere sphere = initSphere((Vector3){0,30,0}, 1, RED);
  sphere.velocity = (Vector3){0,-10,0};

  while (!WindowShouldClose()) {

    float dt = GetFrameTime();
    handleCamera(&camera);
    applyGravity(&sphere);
    updateSphere(&sphere, dt);
    if(sphere.position.y - sphere.radius <= 0 && sphere.velocity.y < 0){
      sphere.position.y = 0 + sphere.radius;
      sphere.velocity.y = -sphere.velocity.y;
    }
    if(IsKeyPressed(KEY_SPACE)){
      sphere.position.y = 20;
      sphere.velocity.y = 0;
      sphere.acceleration.y = 0; 
    }
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
