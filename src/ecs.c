#include "../include/ecs.h"
#include "../include/component.h"
#include "../include/entity.h"

bool ecs_init(int capacity) {
   return (init_stores(capacity) && init_entities(capacity));
    
}

void ecs_stop() {
    free_stores();
}

bool ecs_create(int cmpMask) {
    return (create_entity(cmpMask)); 
}

bool ecs_remove(int id) {
    return (remove_entity(id));
}

EnIter* ecs_keys() {
    return create_enIter();
}

void ecs_next(EnIter* iter) {
    next_enIter(iter);
}

int ecs_key(EnIter* iter) {
    return value_enIter(iter);
}

int ecs_mask(EnIter* iter) {
    return mask_enIter(iter);
}

void ecs_freeIter(EnIter* iter) {
    free_enIter(iter);
}
