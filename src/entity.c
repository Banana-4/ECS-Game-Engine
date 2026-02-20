#include "../include/entity.h"
#include <stdio.h>

PackedEntities* pe;

static int freeIDsize = 0;
static int freeIds[MAX_ENTITIES];
static int nextID = 0;

static int get_id() {
  if (freeIDsize > 0) {
    return freeIds[--freeIDsize];
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
      freeIds[freeIDsize++] = id;
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
    if (pe_remove(pe, id)) {
        freeIds[freeIDsize++] = id;
        return true;
    }
    return false;
}


void kill_entities() {
    pe_free(pe);
    free(pe);
}


bool enIter_init(enIter *iter) {
    if (!iter)
        return false;
    iter->left = pe->size;
    iter->id = pe->id[pe->size - iter->left];
    iter->cmp_mask = pe->cmp_mask[pe->size - iter->left];
    return true;
}

bool enIter_next(enIter *iter) {
    if(--iter->left >= 1) {
        iter->id = pe->id[pe->size - iter->left];
        iter->cmp_mask = pe->cmp_mask[pe->size - iter->left];
        return true;
    }
    return false;
}

bool enIter_getID(enIter *iter, int *out) {
  if(iter && iter->left > 0) {
      *out = iter->id;
      return true;
  }
  return false;
}


bool enIter_getMask(enIter *iter, unsigned *out) {
   if(iter && iter->left > 0) {
       *out = iter->cmp_mask;
       return true;
   }
   return false;
}

void enIter_free(enIter *iter) {
    free(iter);
    iter = NULL;
}

void print_entites_store() {
    pe_print(pe);
}

int en_dump() {
    const char buf[] = "data/buf_en.json";
    const char save[] = "data/entities.json";
    char entity[100];
    FILE *fp = fopen(buf, "w");
    if (!fp) {
        perror("Failed to open buffer file");
        return 1;
    }
    enIter iter;
    if (!enIter_init(&iter)) {
        return -1;
    }
    fputs("{ \"name\" : \"entity\", \"entities\" : [\n", fp);
    while (1) {
        int id;
        unsigned mask;
        enIter_getID(&iter, &id);
        enIter_getMask(&iter, &mask);
        sprintf(entity, "{ \"id\" : %d, \"mask\" : %u }", id, mask);
        fputs(entity, fp);
        if (enIter_next(&iter)) {
            fputs(",\n", fp);
        } else {
            break;
        }
    }
    fputs(" ],\n \"recycled\": [ ", fp);

    for (int i = 0; i < freeIDsize; i++) {
        fprintf(fp, "%d", freeIds[i]);
        if (i < freeIDsize - 2)
            fputs(", ", fp);
    }
    fputs("] }", fp);
    fflush(fp);
    fclose(fp);
    if (rename(buf, save) != 0) {
        perror("Error renaming file");
        return 2;
    }
    return 0;
}
