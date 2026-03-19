#include <raylib.h>
#include <stdio.h>
#include <raymath.h>

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
void handleCamera(Camera3D *camera);
int main(void) {

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib test");

  SetTargetFPS(60);

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, -5.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };    // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

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

    DrawSphere((Vector3){0.0f,0.0f,0.0f}, 1, RED);
    DrawGrid(10, 1.0f); 
    EndMode3D();
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

void handleCamera(Camera3D *camera){
    
  Vector3 movement = {0.0f, 0.0f, 0.0f};
  if(IsKeyDown(KEY_UP)){
    movement.y += 0.1;
  }
  else if (IsKeyDown(KEY_DOWN)) {
    movement.y -= 0.1f;
  }
  else if (IsKeyDown(KEY_RIGHT)) {
    movement.x += 0.1f;
  }
  else if (IsKeyDown(KEY_LEFT)) {
    movement.x -= 0.1f;
  }
  camera->position = Vector3Add(camera->position, movement); 
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
