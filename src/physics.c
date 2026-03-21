#include "physics.h"
#include "object.h"


void applyGravity(struct Sphere *sphere){
  
  sphere->acceleration.y += -9.82;

}
