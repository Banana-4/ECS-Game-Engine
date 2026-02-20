#ifndef MEMORY_H
#define MEMORY_H
#include "memory.h"
#endif

typedef struct {
    int id;
    unsigned int cmp_mask;
    int left;
} enIter;

bool init_entities(int capacity);
int create_entity(int cmp_mask);
bool update_mask_entity(int id, int cmp_mask);

bool remove_entity(int id);
void free_entities();


//iterators

static inline int iter_left(enIter iter) { return iter.left; }
static inline bool iter_valid(enIter iter) { return iter.left != 0; }


bool enIter_init(enIter *iter);
bool enIter_next(enIter *iter);
bool enIter_getID(enIter *iter, int *out);
bool enIter_getMask(enIter *iter, unsigned *out);
void enIter_free(enIter *iter);


//output
int en_dump();
void print_entites_store();
