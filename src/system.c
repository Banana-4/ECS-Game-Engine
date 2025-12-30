#include "../include/system.h"

bool  move_system(Entity e) {
  int mask = 0xFFFFFFFF;
  if ((e.components & postion)  && (e.components & velocity)) {
    Position* positons = (Position*)get_components(position);
    Velocity* velocities = (Velocity*)get_components(velocity);
    if (positons && velocities) {
      positons[e.id].x += velocities[e.id].x;
      positons[e.id].y += velocities[e.id].y;
      return true;
    }
  }
  return false;
}
