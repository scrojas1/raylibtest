#include <raylib.h>
#include <stdio.h>

#define SCREENWIDTH 800
#define SCREENHEIGHT 450

struct Object {
  float x;
  float y;
  int direction;
  float acceleration;
  const int radius;
};

struct Object initBall(int posX, int posY, const int radius);
void handleInput(struct Object*);

int main(void) {

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib test");

  SetTargetFPS(60);

  struct Object ball = initBall(100, 220, 30);

  while (!WindowShouldClose()) {
    // update
    
    handleInput(&ball);
    ball.x += 2 * ball.acceleration * ball.direction;
    int dx = ball.radius;

    
    if (ball.x + dx >= SCREENWIDTH || ball.x - dx <= 0) {
      ball.direction = -ball.direction;
    }

    // draw
    BeginDrawing();

    ClearBackground(GRAY);

    DrawCircle((int)ball.x, (int)ball.y, ball.radius, RED);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}

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
  }
  else if(IsKeyDown(KEY_DOWN)){
    obj->acceleration -= 0.1;
    printf("Acceleration: %f\n", obj->acceleration);
  }
}
