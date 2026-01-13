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

bool pp_has(PackedPositions* pp, int id) {
  if(!pp) return false;
  return (pp->id_map[id] != -1);
}


bool pp_remove(PackedPositions* pp, int id) {
  if(!pp || !pp->x || !pp->y) {
    return false;
  }
  
  int idx = pp->id_map[id];
  if (idx == -1) {
    return false;
  }
 
  pp->size--;
  int lastId = pp->cmp_id[pp->size];

  pp->x[idx] = pp->x[pp->size];
  pp->y[idx] = pp->y[pp->size];
  
  pp->id_map[lastId] = idx;
  pp->cmp_id[idx] = lastId;
  pp->id_map[id] = -1;

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
    printf("Index: %d, ID: %d, X: %d, Y: %d\n", i,pp->cmp_id[i] , pp->x[i], pp->y[i]);
  }
}

bool ph_init(PackedHealths* ph, int capacity) {
  if(!ph || capacity <= 0) return false;
  ph->hp = (double*) malloc(sizeof(double)* capacity);
  if(!ph->hp) return false;
  ph->cmp_id = (int*) malloc(sizeof(int)* capacity);
  if(!ph->cmp_id) {
    free(ph->hp);
    return false;
  }
  ph->capacity = capacity;
  ph->size = 0;
  for(int i = 0; i < MAX_ENTITIES; ++i) {
    ph->id_map[i] = -1;
  }
  return true;
}

bool ph_push(PackedHealths* ph, int id, double hp) {
  if(!ph || ph->capacity == ph->size) return false;
  
  ph->hp[ph->size] = hp;
  ph->cmp_id[ph->size] = id;
  ph->id_map[id] = ph->size;
  ++ph->size;
  return true;
}

bool ph_has(PackedHealths* ph, int id) {
  if(!ph) return false;
  return (ph->id_map[id] != -1);
}

bool ph_remove(PackedHealths* ph, int id) {
  if(!ph) return false;
  
  int idx = ph->id_map[id];
  if (idx == -1) return false;
  ph->size--;
  int lastId = ph->cmp_id[ph->size];

  ph->hp[idx] = ph->hp[ph->size];
  ph->cmp_id[idx] = lastId;

  ph->id_map[lastId] = idx;
  ph->id_map[id] = -1;

  return true;
}

void ph_free(PackedHealths* ph) {
  if(!ph) return;
  free(ph->hp);
  free(ph->cmp_id);
  ph->cmp_id = NULL;
  ph->hp = NULL;
  ph->capacity = 0;
  ph->size = 0;
}

void ph_print(PackedHealths* ph) {
  if(!ph) {
    printf("No health components");
    return;
  }

  for (int i = 0; i < ph->size; ++i)
    printf("Index: %d, ID: %d, HP: %f\n", i, ph->cmp_id[i], ph->hp[i]);
}


bool pe_init(PackedEntities* pe, int capacity) {
  if(!pe) return false;
  pe->id = (int*)malloc(sizeof(int) * capacity);
  if(!pe->id) return false;
  pe->cmp_mask = (unsigned*)malloc(sizeof(unsigned) * capacity);
  if(!pe->cmp_mask) {
    free(pe->id);
    pe->id = NULL:
    return false;
  }
  pe->capacity = capacity;
  pe->size = 0;
  for (int i = 0; i < MAX_ENTITIES; ++i ) {
    pe->id_map[i] = -1;
  }
}

bool pe_push(PackedEntities* pe, int id, unsigned mask) {
  if(!pe) return false;
  if(pe->size == pe->capacity) return false;

  pe->id[pe->size] = id;
  pe->cmp_mask[pe->size] = mask;
  pe->id_map[id] = pe->size;
  pe->size++;

}

bool pe_remove(PackedEntities* pe, int id) {
  if(!pe) return false;


  int idx = pe->id_map[id];
  if(idx == -1) return false;

  pe->size--;
  int lastId = pe->id[pe->size];
  
  pe->id[idx] = lastId;
  pe->cmp_mask[idx] = pe->cmp_mask[pe->size];
  pe->id_map[lastId] = idx;
 
  pe->id_map[id] = -1;

  return true;
}

void pe_free(PackedEntities* pe) {
  if(!pe) return;
  if(pe->id){
    free(pe->id);
    pe->id = NULL;
  }
  if(pe->cmp_mask) {
    free(pe->cmp_mask);
    pe->cmp_mask = NULL;
  }
  pe->size = 0;
  pe->capacity = 0;
  for(int i = 0; i < MAX_ENTITIES; ++i) {
    pe->id_map[i] = -1;
  }
}

void pe_print(PackedEntities* pe) {
  if(!pe) print("No Entities.\n");
  for(int i = 0; i < pe->size; ++i) {
    printf("INDEX: %d, ID: %d, MASK: %d\n", i, pe->id[i], pe->cmp_mask[i]);
  }
}


