#include "memory.h"

typedef struct ppData {
    int x;
    int y;
}ppData;

typedef struct pvData {
    int x;
    int y;
}pvData;

typedef struct phData {
    double hp;
}phData;

typedef struct paData {
    double dmg;
}paData;

typedef struct pasData {
    char ascii;
}pasData;

bool init_stores(int capacity);
void free_stores();

//add new components, create or update
bool position_insert(int id, int x, int y);
bool velocity_insert(int id, int x, int y);
bool health_insert(int id, double hp);
bool ascii_insert(int id, char ch);
bool attack_insert(int id, double dmg);

//read components no change to data
void get_postion(int id, ppData* out);
void get_velocity(int id, pvData* out);
void get_health(int id, phData* out);
void get_attack(int id, paData* out);
void get_ascii(int id, pasData* out);
