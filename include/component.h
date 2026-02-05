#include <stdbool.h>

// base iter

struct BaseIter {
    int *cmp_id;
    int left;
};

//used for point coordiantes, position velocity
struct vec2Iter {
    int *x;
    int *y;
    struct BaseIter base;
};

struct scalarDIter {
    double *val;
    struct BaseIter base;
};

struct scalarChIter {
    char *val;
    struct BaseIter base;
};

typedef struct vec2Iter posIter;
typedef struct vec2Iter velIter;
typedef struct scalarDIter hpIter;
typedef struct scalarDIter attIter;
typedef struct scalarChIter pasIter;

bool init_stores(int capacity);
void free_stores();

//insert and update data interface

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


//iteration interface

static inline int iter_left(BaseIter base) { return base.left; }
static inline bool iter_valid(BaseIter base) { return base.left != 0; }

//position
void posIter_init(posIter *iter);
bool posIter_next(posIter *iter);
bool posIter_getX(posIter *iter, int *out);
bool posIter_getY(posIter *iter, int *out);
bool posIter_getID(posIter *iter, int *out);

static inline int iter_left();

//velocity
void velIter_init(velIter *iter);
bool velIter_next(velIter *iter);
bool velIter_getX(velIter *iter, int *out);
bool velIter_getY(velIter *iter, int *out);
bool velIter_getID(velIter *iter, int *out);

//health

void hpIter_init(hpIter *iter);
bool hpIter_next(hpIter *iter);
bool hpIter_getHP(hpIter *iter, double *out);
bool hpIter_getID(hpIter *iter, int *out);

// Attack

void attIter_init(attIter *iter);
bool attIter_next(attIter *iter);
bool attIter_getDmg(attIter *iter, double *out);
bool attIter_getID(attIter *iter, int *out);


//ASCII ART

void pasIter_init(pasIter *iter);
bool pasIter_next(pasIter *iter);
bool pasIter_getCh(pasIter *iter, char *out);
bool pasIter_getID(pasIter *iter, int *out);
