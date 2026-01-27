#include "../include/ecs.h"
#include "../include/component.h"
#include "../include/entity.h"

bool ecs_init(int capacity) {
   return (init_stores(capacity) && init_entities(capacity));
}

void ecs_stop() {
    free_stores();
    free_entities();
}

bool ecs_create(int cmpMask) {
    int id;
    if ((id = create_entity(cmpMask)) == -1)  {
        return false;
    }
    if(cmpMask & POSITION) {

    }
    if(cmpMask & VELOCITY) {
    }
    if(cmpMask & HEALTH) {

    }
    if(cmpMask & ATTACK){

    }
    if(cmpMask & ASCII){

    }
    return true;
}

bool ecs_remove(int id) {
    //get the cmp mask
    //remove all the components
    //remove the id
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
