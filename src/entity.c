#include "../include/entity.h"

PackedEntities* pe;

static int freeIDsize = -1;
static int freeIds[MAX_ENTITIES];
static int nextID = 0;

static int get_id() {
  if (freeIDsize >= 0) {
    return freeIds[freeIDsize--];
  }
  if(nextID == MAX_ENTITIES - 1) return -1;
  return nextID++;
}

bool init_entities(int capacity) {
  pe = (PackedEntities*)malloc(sizeof(PackedEntities));
  if (!pe)
      return false;
  return pe_init(pe, capacity);

}

int create_entity(int cmp_mask) {
  int id = get_id();
  if (id < 0) return -1;
  if(!pe_insert(pe, id, cmp_mask)) {
      freeIds[++freeIDsize] = id;
      return -1;
  }
  return id;
}

bool update_mask_entity(int id, int cmp_mask) {
    if(pe_has(pe,id)) {
        pe_insert(pe, id, cmp_mask);
        return true;
    }
    return false;
}

bool remove_entity(int id) {
  if(pe_remove(pe, id)) {
    freeIds[++freeIDsize] = id;
    return true;
  }
  return false;
}


void kill_entities() {
  pe_free(pe);
  free(pe);
}


EnIter* create_enIter() {
  EnIter* iter = (EnIter*)malloc(sizeof(EnIter));

  if (!iter)
      return NULL;

  iter->left = pe->size;
  iter->id = pe->id[pe->size - iter->left];
  iter->cmp_mask = pe->cmp_mask[pe->size - iter->left];
  return iter;

}

bool next_enIter(EnIter* iter) {
  if(--iter->left >= 1) {
    iter->id = pe->id[pe->size - iter->left];
    iter->cmp_mask = pe->cmp_mask[pe->size - iter->left];
    return true;
  }
   return false;
}

int id_enIter(EnIter* iter) {
  if(iter) {
    return iter->id;
  }
  return -1;
}


int mask_enIter(EnIter* iter) {
   if(iter) {
    return iter->cmp_mask;
  }
  return -1;
}

void free_enIter(EnIter* iter) {
  free(iter);
  iter = NULL;
}

void print_entites_store() {
    pe_print(pe);
}
