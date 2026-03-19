#include "camera.h"
#include "raylib.h"


Camera3D initCamera(){
  
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 0.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };    // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

  return camera;

}

float theta = 0;
float radius = 10.0f;
Vector3 center = {0,0,0};
float height = 10.0f;

void handleCamera(Camera3D *camera){
   
  if(IsKeyDown(KEY_W)){
    height += 0.2f;
  }
  if (IsKeyDown(KEY_S)) {
    height -= 0.2f;
  }
  if (IsKeyDown(KEY_D)) {
    theta += 0.1f;
  }
  if (IsKeyDown(KEY_A)) {
    theta -= 0.1f;
  }
   
  if(theta > 2*PI){
    theta -= 2*PI;
  }
  if(theta < 0){
    theta += 2*PI;
  }
  camera->position.x = center.x + radius*cos(theta);
  camera->position.z = center.z + radius*sin(theta); 
  camera->position.y = center.y + height;
  camera->target = center;

}

