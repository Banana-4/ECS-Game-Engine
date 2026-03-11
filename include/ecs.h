#ifndef COMPONENT_H
#define COMPONENT_H
#include "../include/component.h"
#endif
#ifndef ENTITY_H
#define ENTITY_H
#include "../include/entity.h"
#endif
#ifndef SYSTEM_H
#define SYSTEM_H
#include "../include/system.h"
#endif


enum ComponentType {
 POSITION = 1,
 VELOCITY = 2,
 HEALTH = 4,
 ATTACK = 8,
 ASCII = 16,
};


typedef struct enIter {
    int *id;
    unsigned int *cmp_mask;
    int left;
}enIter;


//Iterators
int enIter_left(enIter* iter);
bool enIter_valid(enIter* iter);


bool enIter_init(enIter *iter);
bool enIter_next(enIter *iter);
bool enIter_getID(enIter *iter, int *out);
bool enIter_getMask(enIter *iter, unsigned *out);

//Coordinator
bool ecs_init(int capacity);
void ecs_stop();

// Entity manager
int ecs_create_entity();
bool ecs_remove_entity(int id);

bool ecs_add_position(int id, int x, int y);
bool ecs_add_velocity(int id, int x, int y);
bool ecs_add_health(int id, double hp);
bool ecs_add_attack(int id, double dmg);
bool ecs_add_ascii(int id, char ch);

bool ecs_remove_position(int id);
bool ecs_remove_velocity(int id);
bool ecs_remove_health(int id);
bool ecs_remove_attack(int id);
bool ecs_remove_ascii(int id);



//store
bool init_entity_store(int capacity);
bool remove_entity(int id);


int create_entity(int cmp_mask);

//output
void print_entites_store();
