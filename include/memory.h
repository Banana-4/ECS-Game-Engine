#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_ENTITIES 10000
// Stores
typedef struct PackedEntities PackedEntities;
typedef struct PackedVec2Int PackedPositions;
typedef struct PackedVec2Int PackedVelocities;
typedef struct PackedDouble PackedHealths;
typedef struct PackedChar PackedASCII;
typedef struct PackedDouble PackedAttacks;

// Entity store interface
bool pe_init(PackedEntities* pe, size_t capacity);
bool pe_insert(PackedEntities* pe, int id, unsigned mask);
bool pe_has(PackedEntities* pe, int id);
bool pe_remove(PackedEntities* pe, int id);
void pe_free(PackedEntities* pe);
void pe_print(PackedEntities* pe);

//Postion store interface
bool pp_init(PackedPositions* pp, size_t capacity);
bool pp_insert(PackedPositions* pp, int id, int x, int y);

bool pp_has(PackedPositions* pp, int id);

bool pp_remove(PackedPositions* pp, int id);
void pp_free(PackedPositions* pp);
void pp_print(PackedPositions* pp);


// Health store interface
bool ph_init(PackedHealths* ph, size_t capacity);
bool ph_insert(PackedHealths* ph, int id, double hp);
bool ph_has(PackedHealths* ph, int id);
bool ph_remove(PackedHealths* ph, int id);
void ph_free(PackedHealths* ph);
void ph_print(PackedHealths* ph);

//Velocity store interface
bool pv_init(PackedVelocities* pv, size_t capacity);
bool pv_insert(PackedVelocities* pv, int id, int x, int y);
bool pv_has(PackedVelocities* pv, int id);
bool pv_remove(PackedVelocities* pv, int id);
void pv_free(PackedVelocities* pv);
void pv_print(PackedVelocities* pv);


// ASCII store interface
bool pas_init(PackedASCII* pas, size_t capacity);
bool pas_insert(PackedASCII* pas, int id, char ch);
bool pas_has(PackedASCII* pas, int id);
bool pas_remove(PackedASCII* pas, int id);
void pas_free(PackedASCII* pas);
void pas_print(PackedASCII* pas);

//Attack store interface
bool pa_init(PackedAttacks *pa, size_t capacity);
bool pa_insert(PackedAttacks* pa, int id, double dmg);
bool pa_has(PackedAttacks* pa, int id);
bool pa_remove(PackedAttacks* pa, int id);
void pa_free(PackedAttacks* pa);
void pa_print(PackedAttacks* pa);
