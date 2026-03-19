#include <raylib.h>
#include <raymath.h>

#include "camera.h"
#include "particle.h"

#define SCREENWIDTH 800
#define SCREENHEIGHT 450

void handleInput(struct Object *);

int main(void) {

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib test");

  SetTargetFPS(60);

  Camera3D camera = initCamera();
  struct Object ball = initBall(100, 220, 30);

  while (!WindowShouldClose()) {
    // update

    //    handleInput(&ball);
    ball.x += 2 * ball.acceleration * ball.direction;
    int dx = ball.radius;

    if (ball.x + dx >= SCREENWIDTH || ball.x - dx <= 0) {
      ball.direction = -ball.direction;
    }
    handleCamera(&camera);
    // draw
    BeginDrawing();
    ClearBackground(GRAY);
    BeginMode3D(camera);
    //     DrawCircle(ball.x, ball.y, 30, RED);
    DrawSphere((Vector3){0.0f, 0.0f, 0.0f}, 1, RED);
    DrawGrid(10, 1.0f);
    //    handleInput(&ball);
    EndMode3D();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
