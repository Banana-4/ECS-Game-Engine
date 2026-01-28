#include "memory.h"


typedef struct {
    int id;
    unsigned int cmp_mask;
    int left;
} EnIter;

bool init_entities(int capacity);
int create_entity(int cmp_mask);
bool update_mask_entity(int id, int cmp_mask);

bool remove_entity(int id);
void free_entities();



//read only
EnIter* create_enIter();
bool next_enIter(EnIter* iter);
int id_enIter(EnIter* iter);
int mask_enIter(EnIter* iter);
void free_enIter(EnIter* iter);

//debug

void print_entites_store();
