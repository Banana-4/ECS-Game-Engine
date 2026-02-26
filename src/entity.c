#include "../include/entity.h"

static int freeIDsize = 0;
static int freeIds[MAX_ENTITIES];
static int nextID = 0;

int get_id() {
  if (freeIDsize > 0) {
    return freeIds[--freeIDsize];
  }
  if(nextID == MAX_ENTITIES - 1) return -1;
  return nextID++;
}

void recycle_id(int id) {
  freeIds[freeIDsize++] = id;
}
