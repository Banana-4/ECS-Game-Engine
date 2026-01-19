#include "../include/memory.h"
#include <cstdlib>
#include <stdlib.h>

bool pp_init(PackedPositions* pp, int capacity) {
  if (capacity <= 0) {
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

  pp->capacity = capacity;
  pp->size = 0;

  return true;
}

bool pp_insert(PackedPositions* pp, int id, int x, int y) {
  if(pp->size == pp->capacity) {
    return false;
  }
  int idx = pp->id_map[id];
  if(idx == -1) {
      pp->x[pp->size] = x;
      pp->y[pp->size] = y;
      pp->cmp_id[pp->size] = id;
      pp->id_map[id] = pp->size;
      pp->size++;
  } else {
    pp->x[idx] = x;
    pp->y[idx] = y;
  }
  return true;

}

bool pp_has(PackedPositions* pp, int id) {
  return (pp->id_map[id] != -1);
}


bool pp_remove(PackedPositions* pp, int id) {
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
    printf("Size: %d, Capacity: %d\n", pp->size, pp->capacity);
    for(int i = 0; i < pp->size; i++) {
        printf("Index: %d, ID: %d, X: %d, Y: %d\n", i,pp->cmp_id[i] , pp->x[i], pp->y[i]);
  }
}

bool ph_init(PackedHealths* ph, int capacity) {
  if(capacity <= 0) return false;
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

bool ph_insert(PackedHealths* ph, int id, double hp) {
  if(ph->capacity == ph->size) return false;
  int idx = ph->id_map[id];
  if( idx == -1 ) {
      ph->hp[ph->size] = hp;
      ph->cmp_id[ph->size] = id;
      ph->id_map[id] = ph->size;
      ++ph->size;
  } else {
      ph->hp[idx] = hp;
  }
  return true;
}

bool ph_has(PackedHealths* ph, int id) {
  return (ph->id_map[id] != -1);
}

bool ph_remove(PackedHealths* ph, int id) {
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
  free(ph->hp);
  free(ph->cmp_id);
  ph->cmp_id = NULL;
  ph->hp = NULL;
  ph->capacity = 0;
  ph->size = 0;
}

void ph_print(PackedHealths* ph) {
    printf("Size: %d, Capacity: %d\n", ph->size, ph->capacity);
    for (int i = 0; i < ph->size; ++i)
        printf("Index: %d, ID: %d, HP: %f\n", i, ph->cmp_id[i], ph->hp[i]);
}


bool pe_init(PackedEntities* pe, int capacity) {
  pe->id = (int*)malloc(sizeof(int) * capacity);
  if(!pe->id) return false;
  pe->cmp_mask = (unsigned*)malloc(sizeof(unsigned) * capacity);
  if(!pe->cmp_mask) {
    free(pe->id);
    pe->id = NULL;
    return false;
  }
  pe->capacity = capacity;
  pe->size = 0;
  for (int i = 0; i < MAX_ENTITIES; ++i ) {
    pe->id_map[i] = -1;
  }
}

bool pe_insert(PackedEntities* pe, int id, unsigned mask) {
  if(pe->size == pe->capacity) return false;
  int idx = pe->id_map[id];
  if (idx == -1) {
      pe->id[pe->size] = id;
      pe->cmp_mask[pe->size] = mask;
      pe->id_map[id] = pe->size;
      pe->size++;
  } else {
      pe->cmp_mask[idx] = mask;
  }
  return true;
}

bool pe_remove(PackedEntities* pe, int id) {

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
    free(pe->id);
    pe->id = NULL;
    free(pe->cmp_mask);
    pe->cmp_mask = NULL;
    pe->size = 0;
    pe->capacity = 0;
    for(int i = 0; i < MAX_ENTITIES; ++i) {
        pe->id_map[i] = -1;
    }
}

void pe_print(PackedEntities *pe) {
    printf("Size: %d, Capacity: %d\n", pe->size, pe->capacity);
    for(int i = 0; i < pe->size; ++i) {
        printf("INDEX: %d, ID: %d, MASK: %d\n", i, pe->id[i], pe->cmp_mask[i]);
    }
}


bool pv_init(PackedVelocities *pv, int capacity) {
  if (capacity <= 0)
    return false;
  pv->x = (int *)malloc(sizeof(int) * capacity);
  if (!pv->x) {
      return false;
  }
  pv->y = (int *)malloc(sizeof(int) * capacity);
  if (!pv->y) {
    free(pv->x);
    pv->x = NULL;
    return false;
  }
  pv->cmp_id = (int *)malloc(sizeof(int) * capacity);
  if (!pv->cmp_id) {
    free(pv->x);
    free(pv->y);
    pv->x = NULL;
    pv->y = NULL;
    return false;
  }
  pv->capacity = capacity;
  pv->size = 0;
  for (int i = 0; i < MAX_ENTITIES; ++i) {
      pv->id_map[i] = -1;
  }
  return true;
}

bool pv_insert(PackedVelocities *pv, int id, int x, int y) {
  if (pv->size == pv->capacity) {
      return false;
  }
  int idx = pv->id_map[id];
  if (idx == -1) {
    pv->x[pv->size] = x;
    pv->y[pv->size] = y;
    pv->cmp_id[pv->size] = id;
    pv->id_map[id] = pv->size;
    pv->size++;
  } else {
    pv->x[idx] = x;
    pv->y[idx] = y;
    pv->size++;
  }
  return true;
}

bool pv_remove(PackedVelocities *pv, int id) {
  int idx = pv->id_map[id];
  if (idx == -1) {
      return false;
  }
  pv->size--;
  int lastId = pv->cmp_id[pv->size];
  pv->x[idx] = pv->x[pv->size];
  pv->y[idx] = pv->y[pv->size];
  pv->cmp_id[idx] = lastId;
  pv->id_map[id] = -1;
  pv->id_map[lastId] = idx;
  return true;
}

bool pv_has(PackedVelocities *pv, int id) { return (pv->id_map[id] != -1); }

void pv_free(PackedVelocities *pv) {
  free(pv->x);
  free(pv->y);
  free(pv->cmp_id);
  pv->size = 0;
  pv->capacity = 0;
  pv->cmp_id = NULL;
  pv->x = NULL;
  pv->y = NULL;
  for (int i = 0; i < MAX_ENTITIES; ++i) {
      pv->id_map[i] = -1;
  }
}

void pv_print(PackedVelocities *pv) {
    printf("Size: %d, Capacity: %d \n", pv->size, pv->capacity);
    for(int i = 0; i < pv->size; ++i) {
        printf("INDEX: %d, ID: %d, Speed X: %d, Speed Y: %d, \n", i, pv->cmp_id[i], pv->x[i], pv->y[i]);
  }
}


bool pas_init(PackedASCII *pas, int capacity) {
  if (!pas || capacity <= 0)
    return false;
  pas->ascii = (char *)malloc(sizeof(char) * capacity);
  if (!pas->ascii)
    return false;
  pas->cmp_id = (int *)malloc(sizeof(int) * capacity);
  if (!pas->cmp_id) {
    free(pas->ascii);
    pas->ascii = NULL;
    return false;
  }
  pas->size = 0;
  pas->capacity = capacity;
  for (int i = 0; i < MAX_ENTITIES; i++) {
      pas->id_map[i] = -1;
  }
  return true;
}

bool pas_insert(PackedASCII *pas, int id, char ch) {
  if (pas->size == pas->capacity) {
      return false;
  }
    int idx = pas->id_map[id];
    if (idx == -1) {
      pas->ascii[pas->size] = ch;
      pas->cmp_id[pas->size] = id;
      pas->id_map[id] = pas->size;
      pas->size++;
    } else {
        pas->ascii[idx] = ch;
    }
    return true;
}

bool pas_remove(PackedASCII *pas, int id) {
  int idx = pas->id_map[id];
  if (id == -1)
    return false;
  pas->size--;
  int lastId = pas->cmp_id[pas->size];
  pas->ascii[idx] = pas->ascii[pas->size];
  pas->cmp_id[idx] = lastId;
  pas->id_map[id] = -1;
  pas->id_map[lastId] = idx;
  return true;
}

bool pas_has(PackedASCII *pas, int id) { return (pas->id_map[id] != -1); }

void pas_free(PackedASCII *pas) {
  free(pas->ascii);
  pas->ascii = NULL;
  free(pas->cmp_id);
  pas->cmp_id = NULL;
  pas->size = 0;
  pas->capacity = 0;
}

void pas_print(PackedASCII *pas) {
    printf("Size: %d, Capacity: %d \n", pas->size, pas->capacity);
    for(int i = 0; i < pas->size; ++i) {
        printf("INDEX: %d, ID: %d, ASCII Art: %c \n", i, pas->cmp_id[i], pas->ascii[i]);
  }
}

bool pa_init(PackedAttacks *pa, int capacity) {
    if (!pa || capacity <= 0) return false;
    pa->dmg = (double *)malloc(sizeof(double) * capacity);
    if (!pa->dmg)
      return false;
    pa->cmp_id = (int *)malloc(sizeof(int) * capacity);
    if (!pa->cmp_id) {
      free(pa->dmg);
      pa->dmg = NULL;
      return false;
    }
    pa->size = 0;
    pa->capacity = capacity;
    for (int i = 0; i < MAX_ENTITIES; ++i) {
        pa->id_map[i] = -1;
    }
    return true;
}

bool pa_insert(PackedAttacks *pa, int id, double dmg) {
    if (pa->size == pa->capacity) {
      return false;
  }
    int idx = pa->id_map[id];
    if (idx == -1) {
      pa->dmg[pa->size] = dmg;
      pa->cmp_id[pa->size] = id;
      pa->id_map[id] = pa->size;
      pa->size++;
    } else {
        pa->dmg[idx] = dmg;
    }
    return true;

}

bool pa_has(PackedAttacks *pa, int id) {
   return (pa->id_map[id] != -1);

}

bool pa_remove(PackedAttacks *pa, int id) {
    int idx = pa->id_map[id];
    if (id == -1)
        return false;
  pa->size--;
  int lastId = pa->cmp_id[pa->size];
  pa->dmg[idx] = pa->dmg[pa->size];
  pa->cmp_id[idx] = lastId;
  pa->id_map[id] = -1;
  pa->id_map[lastId] = idx;
  return true;
}

void pa_free(PackedAttacks *pa) {
  free(pa->dmg);
  pa->dmg = NULL;
  free(pa->cmp_id);
  pa->cmp_id = NULL;
  pa->size = 0;
  pa->capacity = 0;
  for (int i = 0; i < MAX_ENTITIES; i++) {
      pa->id_map[i] = -1;
  }
}

void pa_print(PackedAttacks *pa) {
  printf("Size: %d, Capacity: %d \n", pa->size, pa->capacity);
    for(int i = 0; i < pa->size; ++i) {
        printf("INDEX: %d, ID: %d, DMG: %f \n", i, pa->cmp_id[i], pa->dmg[i]);
  }

}
