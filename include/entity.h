#include "memory.h"


typedef struct {
    int* id;
    int* cmp_mask;
    int pos;
} EnIter;

bool init_entities(int capacity);
bool create_entity(int cmp_mask);
bool remove_entity(int id);
void free_entities();

EnIter* create_enIter();
void next_enIter(EnIter* iter);
int id_enIter(EnIter* iter);
int mask_enIter(EnIter* iter);
void free_enIter(EnIter* iter);


