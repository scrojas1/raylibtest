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

double theta = 0;
float radius = 10;
Vector3 center = {0,0,0};

void handleCamera(Camera3D *camera){
   
  //move camera position
  Vector3 movement = {0.0f, 0.0f, 0.0f};
  if(IsKeyDown(KEY_W)){
    movement.y += 0.1;
  }
  else if (IsKeyDown(KEY_S)) {
    movement.y -= 0.1f;
  }
  else if (IsKeyDown(KEY_D)) {
    theta += 0.1f;
  }
  else if (IsKeyDown(KEY_A)) {
    theta -= 0.1f;
  }
   

  camera->position.x = center.x + radius*cos(theta);
  camera->position.z = center.z + radius*sin(theta); 
  camera->position = Vector3Add(camera->position, movement); 
  

}

