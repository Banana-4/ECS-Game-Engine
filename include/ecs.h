#include "../include/system.h"

bool ecs_init(int capacity);
void ecs_stop();

bool ecs_create(int cmpMask);
bool ecs_remove(int id);
