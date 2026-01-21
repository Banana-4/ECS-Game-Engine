#include "../include/system.h"

bool ecs_init(int capacity);
void ecs_stop();

bool ecs_create(int cmpMask);
bool ecs_remove(int id);

EnIter* ecs_keys();
void ecs_next(EnIter* iter);
int ecs_key(EnIter* iter);
int ecs_mask(EnIter* iter)
void ecs_freeIter(EnIter* iter);