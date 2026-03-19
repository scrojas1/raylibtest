#include "camera.h"


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
float radius = 10;
Vector3 center = {0,0,0};
float height = 0;

void handleCamera(Camera3D *camera){
   
  //move camera position
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
   

  camera->position.x = center.x + radius*cos(theta);
  camera->position.z = center.z + radius*sin(theta); 
  camera->position.y = height;
  camera->target = center;

}

