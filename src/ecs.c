#include "../include/ecs.h"

PackedEntities* pe;
//Iterators
struct enIter {
    int id;
    unsigned int cmp_mask;
    int left;
};


bool init_entity_store(int capacity) {
  pe = (PackedEntities*)malloc(sizeof(PackedEntities));
  if (!pe)
      return false;
  return pe_init(pe, capacity);
}

bool ecs_init(int capacity) {
   return (init_stores(capacity) && init_entity_store(capacity));
}

void ecs_stop() {
    free_stores();
    free_entities();
}

//creates a componentless entity

int ecs_create_entity() {
    int id = get_id();
    if (id < 0) {
        return -1;
    }

    if (!pe_insert(pe, id, 0)) {
            recycle_id(id);
            return -1;
    }

    return id;
}

bool ecs_removeID(int id) {
    if (!pe_has(pe, id))
        return false;
    unsigned mask;
    pe_get(pe, id, &mask);
    if (mask & POSITION) {
        position_remove(id);
    }
    if (mask & VELOCITY) {
        velocity_remove(id);
    }
    if (mask & HEALTH) {
        health_remove(id);
    }
    if (mask & ATTACK) {
        attack_remove(id);
    }
    if (mask & ASCII) {
        ascii_remove(id);
    }
    pe_remove(pe, id);
    recycle_id(id);
    return true;
}

bool ecs_add_position(int id, int x, int y) {
    if (!pe_has(pe, id))
      return false;

    unsigned mask;
    pe_get(pe, id, &mask);
    if (mask & POSITION)
        return false;
    mask = mask | POSITION;
    if (!position_insert(id, x, y)) {
        return false;
    }
    pe_insert(pe, id, mask);
    return true;
}


bool ecs_add_velocity(int id, int x, int y) {
    if (!pe_has(pe, id))
      return false;

    unsigned mask;
    pe_get(pe, id, &mask);
    if (mask & VELOCITY)
        return false;
    mask = mask | VELOCITY;
    if (!velocity_insert(id, x, y)) {
        return false;
    }
    pe_insert(pe, id, mask);
    return true;
}

bool ecs_add_health(int id, double hp) {
    if (!pe_has(pe, id))
      return false;

    unsigned mask;
    pe_get(pe, id, &mask);
    if (mask & HEALTH)
        return false;
    mask = mask | HEALTH;
    if (!health_insert(id, hp)) {
        return false;
    }
    pe_insert(pe, id, mask);
    return true;
}

bool ecs_add_attack(int id, double dmg) {
    if (!pe_has(pe, id))
      return false;

    unsigned mask;
    pe_get(pe, id, &mask);
    if (mask & ATTACK)
        return false;
    mask = mask | ATTACK;
    if (!attack_insert(id, dmg)) {
        return false;
    }
    pe_insert(pe, id, mask);
    return true;
}

bool ecs_add_ascii(int id, char ch) {
    if (!pe_has(pe, id))
      return false;

    unsigned mask;
    pe_get(pe, id, &mask);
    if (mask & ASCII)
        return false;
    mask = mask | ASCII;
    if (!ascii_insert(id, ch)) {
        return false;
    }
    pe_insert(pe, id, mask);
    return true;
}

bool ecs_remove_position(int id) {
    if (!pe_has(pe, id))
        return false;
    unsigned mask;
    pe_get(pe, id, &mask);
    if (!(mask & POSITION))
        return false;
    if (!position_remove(id))
        return false;
    pe_insert(pe, id, mask ^ POSITION);
    return true;
}

bool ecs_remove_velocity(int id) {
    if (!pe_has(pe, id))
        return false;
    unsigned mask;
    pe_get(pe, id, &mask);
    if (!(mask & VELOCITY))
        return false;
    if (!velocity_remove(id))
        return false;
    pe_insert(pe, id, mask ^ VELOCITY);
    return true;
}

bool ecs_remove_health(int id) {
    if (!pe_has(pe, id))
        return false;
    unsigned mask;
    pe_get(pe, id, &mask);
    if (!(mask & HEALTH))
        return false;
    if (!health_remove(id))
        return false;
    pe_insert(pe, id, mask ^ HEALTH);
    return true;
}

bool ecs_remove_attack(int id) {
    if (!pe_has(pe, id))
        return false;
    unsigned mask;
    pe_get(pe, id, &mask);
    if (!(mask & ATTACK))
        return false;
    if (!attack_remove(id))
        return false;
    pe_insert(pe, id, mask ^ ATTACK);
    return true;
}
bool ecs_remove_ascii(int id) {
    if (!pe_has(pe, id))
        return false;
    unsigned mask;
    pe_get(pe, id, &mask);
    if (!(mask & ASCII))
        return false;
    if (!ascii_remove(id))
        return false;
    pe_insert(pe, id, mask ^ ASCII);
    return true;
}

// Iterators

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

inline int enIter_left(enIter* iter) { return iter->left; }
inline bool enIter_valid(enIter* iter) { return iter->left != 0; }

//debug & out

void print_entites_store() {
    pe_print(pe);
}


//garbage
bool update_mask_entity(int id, int cmp_mask) {
    if(pe_has(pe,id)) {
        pe_insert(pe, id, cmp_mask);
        return true;
    }
    return false;
}


bool remove_entity(int id) {
   return pe_remove(pe, id);
}


void kill_entities() {
    pe_free(pe);
    free(pe);
}
