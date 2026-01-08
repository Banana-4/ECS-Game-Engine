#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_ENTITIES 10000

typedef struct {
  int* x;
  int* y;
  int capacity;
  int size;
  
  int* cmp_id;
  int id_map[MAX_ENTITIES];
} PackedPositions;

bool pp_init(PackedPositions* pp, int capacity);
bool pp_push(PackedPositions* pp, int id, int x, int y);
bool pp_remove(PackedPositions* pp, int id);
void pp_free(PackedPositions* pp);
void pp_print(PackedPositions* pp);




