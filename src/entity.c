#include "../include/entity.h"
PackedEntities* pe;

static int freeIDsize = -1;
static int freeIds[MAX_ENTITIES];
static int nextID = 0;

static int get_id() {
  if (freeIDsize >= 0) {
    return freeIds[freeIDsize--];
  }
  if(nextID == MAX_ENTITIES) return -1;

  return nextID++;
}

bool init_entities(int capacity) {
  pe = (PackedEntities*)malloc(sizeof(PackedEntities));
  return pe_init(pe, capacity);
}

bool create_entity(int cmp_mask) {
  int id = get_id();
  if (id < 0) return false;
  return pe_push(pe, id, cmp_mask);
}

bool remove_entity(int id) {
  if( pe_remove(pe, id)) {
    freeIds[++freeIDsize] = id;
    return true;
  }
  return false;
}


PackedEntities* get_entites() {
    return pe;
}

void kill_entities() {
  pe_free(pe);
  free(pe);
}
