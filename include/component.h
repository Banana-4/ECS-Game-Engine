#include <stdbool.h>

//used for point coordiantes, position velocity
struct vec2Iter {
    int *x;
    int *y;
    int *cmp_id;
    int left;
};

struct scalarDIter {
    double *val;
    int *cmp_id;
    int left;
};

struct scalarChIter {
    char *value;
    int *cmp_id;
    int left;
};

typedef struct vec2Iter posIter;
typedef struct vec2Iter velIter;
typedef struct scalarDIter hpIter;
typedef struct scalarDIter attIter;
typedef struct scalarChIter pasIter;

bool init_stores(int capacity);
void free_stores();

//insert data interface

bool position_insert(int id, int x, int y);
bool velocity_insert(int id, int x, int y);
bool health_insert(int id, double hp);
bool ascii_insert(int id, char ch);
bool attack_insert(int id, double dmg);

//remove interface

bool position_remove(int id);
bool velocity_remove(int id);
bool health_remove(int id);
bool ascii_remove(int id);
bool attack_remove(int id);

//get

//iteration interface

//position
void posIter_init(posIter *iter);
bool posIter_next(posIter *iter);
int posIter_getX(posIter *iter);
int posIter_getY(posIter *iter);
int posIter_getID(posIter *iter);

//velocity
void velIter_init(velIter *iter);
bool velIter_next(velIter *iter);
int velIter_getX(velIter *iter);
int velIter_getY(velIter *iter);
int velIter_getID(velIter *iter);

//health

void hpIter_init(hpIter *iter);
bool hpIter_next(hpIter *iter);
double hpIter_getHP(hpIter *iter);
int hpIter_getID(hpIter *iter);

// Attack

void attIter_init(attIter *iter);
bool attIter_next(attIter *iter);
double attIter_getDmg(attIter *iter);
int attIter_getID(attIter *iter);


//ASCII ART

void pasIter_init(pasIter *iter);
bool pasIter_next(pasIter *pas);
char pasIter_getCh(pasIter *pas);
int pasIter_getID(pasIter *pas);
