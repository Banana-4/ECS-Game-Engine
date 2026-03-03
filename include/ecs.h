#include "../include/system.h"
#ifndef COMPONENTS_H
#define COMPONENTS_H
#include "../include/component.h"
#endif
#ifndef ENTITY_H
#define ENTITY_H
#include "../include/entity.h"
#endif


enum ComponentType {
 POSITION = 1,
 VELOCITY = 2,
 HEALTH = 4,
 ATTACK = 8,
 ASCII = 16,
};


typedef struct enIter enIter;

//Iterators
 inline int enIter_left(enIter* iter);
 inline bool enIter_valid(enIter* iter);


bool enIter_init(enIter *iter);
bool enIter_next(enIter *iter);
bool enIter_getID(enIter *iter, int *out);
bool enIter_getMask(enIter *iter, unsigned *out);
void enIter_free(enIter *iter);

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
void free_entities();


int create_entity(int cmp_mask);
bool update_component_mask(int id, int cmp_mask);

//output
int enMod_dump();
void print_entites_store();
