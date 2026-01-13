#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_ENTITIES 10000

typedef struct {
  int* id;
  unsigned* cmp_mask;
  int capacity;
  int size;
  
  int id_map[MAX_ENTITIES];
} PackedEntities;

bool pe_init(PackedEntities* pe, int capacity);
bool pe_push(PackedEntities* pe, int id, unsigned mask);
bool pe_remove(PackedEntities* pe, int id);
void pe_free(PackedEntities* pe);
void pe_print(PackedEntities* pe);

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

bool pp_has(PackedPositions* pp, int id);

bool pp_remove(PackedPositions* pp, int id);
void pp_free(PackedPositions* pp);
void pp_print(PackedPositions* pp);



typedef struct {
  double* hp;
  int capacity;
  int size;
  
  int* cmp_id;
  int id_map[MAX_ENTITIES];
} PackedHealths;

bool ph_init(PackedHealths* ph, int capacity);
bool ph_push(PackedHealths* ph, int id, double hp);
bool ph_has(PackedHealths* ph, int id);
bool ph_remove(PackedHealths* ph, int id);
void ph_free(PackedHealths* ph);
void ph_print(PackedHealths* ph);
