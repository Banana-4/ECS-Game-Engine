#include "../include/memory.h"
#define MAXSIZE 32
static Positon positions[MAXSIZE];
static Velocity velocities[MAXSIZE];
static Health healths[MAXSIZE];
static Attack attacks[MAXSIZE];

void* get_components(ComponentsID id) {
switch (id) {
    case position:
      return positions;
    case velocity:
      return velocities;
    case health:
      return healths;
    case attack:
      return attacks;
    default:
      return NULL;
}
}
