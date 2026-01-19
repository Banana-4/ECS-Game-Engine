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
bool pe_insert(PackedEntities* pe, int id, unsigned mask);
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
bool pp_insert(PackedPositions* pp, int id, int x, int y);

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
bool ph_insert(PackedHealths* ph, int id, double hp);
bool ph_has(PackedHealths* ph, int id);
bool ph_remove(PackedHealths* ph, int id);
void ph_free(PackedHealths* ph);
void ph_print(PackedHealths* ph);

typedef struct {
  int *x;
  int *y;

  int capacity;
  int size;

  int* cmp_id;
  int id_map[MAX_ENTITIES];
} PackedVelocities;

bool pv_init(PackedVelocities* pv, int capacity);
bool pv_insert(PackedVelocities* pv, int id, int x, int y);
bool pv_has(PackedVelocities* pv, int id);
bool pv_remove(PackedVelocities* pv, int id);
void pv_free(PackedVelocities* pv);
void pv_print(PackedVelocities* pv);


typedef struct {
  char* ascii;
  int capacity;
  int size;

  int* cmp_id;
  int id_map[MAX_ENTITIES];
} PackedASCII;

bool pas_init(PackedASCII* pas, int capacity);
bool pas_insert(PackedASCII* pas, int id, char ch);
bool pas_has(PackedASCII* pas, int id);
bool pas_remove(PackedASCII* pas, int id);
void pas_free(PackedASCII* pas);
void pas_print(PackedASCII* pas);


typedef struct {
  double* dmg;
  int capacity;
  int size;

  int *cmp_id;
  int id_map[MAX_ENTITIES];
} PackedAttacks;

bool pa_init(PackedAttacks *ph, int capacity);
bool pa_insert(PackedAttacks* ph, int id, double hp);
bool pa_has(PackedAttacks* ph, int id);
bool pa_remove(PackedAttacks* ph, int id);
void pa_free(PackedAttacks* ph);
void pa_print(PackedAttacks* ph);
