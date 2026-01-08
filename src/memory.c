#include "../include/memory.h"

bool pp_init(PackedPositions* pp, int capacity) {
  if (!pp || capacity <= 0) {
    return false;
  }
  pp->x = (int*)malloc(sizeof(int) * capacity);
  if(!pp->x) { return false; }

  pp->y =  (int*)malloc(sizeof(int) * capacity);
  if(!pp->y) {
    free(pp->x);
    return false;
  }

  pp->cmp_id = (int*) malloc(sizeof(int) * capacity);
  if(!pp->cmp_id) {
    free(pp->x);
    free(pp->y);
    return false;
  }

  for (int i = 0; i < MAX_ENTITIES; i++) 
    pp->id_map[i] = -1;

  pa->capacity = capacity;
  pa->size = 0;

  return true;
}

bool pp_push(PackedPositions* pp, int id, int x, int y) {
  if(!pp->x || !p->y) {
    return false;
  }

  if(pp->size == pp->capacity) {
    return false;
  }
  
  pp->x[pp->size] = x;
  pp->y[pp->size] = y;
  
  pp->cmp_id[pp->size] = id;
  pp->id_map[id] = pp->size;

  pp->size++;

  return true;

}

bool pp_remove(PackedPositions* pp, int i) {
  if(!pp || !pp->x || !pp->y) {
    return false;
  }
  
  if (i >= pp->size || i < 0) {
    return false;
  }
  
  pp->size--;
  pp->x[i] = pp->x[pp->size];
  pp->y[i] = pp->y[pp->size];
  
  int id = pp->cmp_id[pp->size];
  pp->cmp_id[pp->size] = -1;
  pp->id_map[pp->cmp_id[i]] = -1;
  pp->id_map[id] = i;
  pp->cmp_id[i] = id;


  return true;
}

void pp_free(PackedPositions* pp) {
  if (!pp) return;
  free(pp->x);
  free(pp->y);
  free(pp->cmp_id);

  pp->size = 0;
  pp->capacity = 0;
  pp->x = NULL;
  pp->y = NULL;
  pp->cmp_id = NULL;
}

void pp_print(PackedPositions* pp) {
  if(!pp) {
    printf("No position components");
    return;
  }
  for(int i = 0; i < pa->size; i++) {
    printf("Index: %d X: %d Y: %d\n", i, pp->x[i], pp->y[i]);
  }
}
