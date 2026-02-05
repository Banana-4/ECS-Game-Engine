#include "../include/component.h"
#include "../include/memory.h"
#include <stdbool.h>
#include <stdlib.h>

PackedPositions* pp; 
PackedHealths* ph;
PackedVelocities* pv;
PackedAttacks *pa;
PackedASCII* pas;




bool init_stores(int capacity) {
  pp = (PackedPositions*)malloc(sizeof(PackedPositions));
  if (!pp_init(pp, capacity)) {
    return false;
  }
  ph = (PackedHealths*)malloc(sizeof(PackedHealths));
  if(!ph_init(ph, capacity)) {
    pp_free(pp);
    return false;
  }
  pv = (PackedVelocities*)malloc(sizeof(PackedVelocities));
  if (!pv_init(pv, capacity)) {
    pp_free(pp);
    ph_free(ph);
    return false;
  }
  pas = (PackedASCII*)malloc(sizeof(PackedASCII));
  if (!pas_init(pas, capacity)) {
    pp_free(pp);
    ph_free(ph);
    pv_free(pv);
    return false;
  }
  pa = (PackedAttacks*)malloc(sizeof(PackedAttacks));
  if (!pa_init(pa, capacity)) {
    pp_free(pp);
    ph_free(ph);
    pv_free(pv);
    pas_free(pas);
    return false;
  }
  return true;
}

void free_stores() {
  pp_free(pp);
  ph_free(ph);
  pv_free(pv);
  pas_free(pas);
  pa_free(pa);
}

// insert and update data interface

bool position_insert(int id, int x, int y) { return pp_insert(pp, id, x, y); }

bool velocity_insert(int id, int x, int y) { return pv_insert(pv, id, x, y); }

bool health_insert(int id, double hp) { return ph_insert(ph, id, hp); }

bool ascii_insert(int id, char ch) { return pas_insert(pas, id, ch); }

bool attack_insert(int id, double dmg) { return pa_insert(pa, id, dmg); }


//remove interface

bool position_remove(int id) { return pp_remove(pp, id); }

bool velocity_remove(int id) { return pv_remove(pv, id); }

bool health_remove(int id) { return ph_remove(ph,id); }

bool ascii_remove(int id) { return pas_remove(pas, id); }

bool attack_remove(int id) { return pa_remove(pa,id); }


//iteration interface


//position
void posIter_init(posIter *iter) {
    if (!iter) {
        return;
    }
    iter->x = pp->x;
    iter->y = pp->y;
    iter->base.cmp_id = pp->cmp_id;
    iter->base.left = pp->size;
}

bool posIter_next(posIter *iter) {
    if (!iter || iter->base.left == 0) {
        return false;
    }

    iter->x++;
    iter->y++;
    iter->base.cmp_id++;
    return --iter->base.left;
}

bool posIter_getX(posIter *iter, int *out) {
    if (!iter || iter->base.left == 0)
        return false;
    *out = *iter->x;
    return true;
}

bool posIter_getY(posIter *iter, int *out) {
    if (!iter || iter->base.left == 0)
        return false;
    *out = *iter->y;
    return true;
}

bool posIter_getID(posIter *iter, int *out) {
    if (!iter || iter->base.left == 0)
        return false;
    *out = *iter->base.cmp_id;
    return true;
}

//velocity
void velIter_init(velIter *iter) {
    if (!iter) {
        return;
    }
    iter->x = pp->x;
    iter->y = pp->y;
    iter->base.cmp_id = pp->cmp_id;
    iter->base.left = pp->size;
}

bool velIter_next(velIter *iter) {
    if (!iter || iter->base.left == 0) {
       return false;
    }

    iter->x++;
    iter->y++;
    iter->base.cmp_id++;
    return --iter->base.left;
}

bool velIter_getX(velIter *iter, int *out) {
    if (!iter || iter->base.left == 0)
      return false;
    *out = *iter->x;
    return true;
}
bool velIter_getY(velIter *iter, int *out) {
    if (!iter || iter->base.left == 0)
      return false;
    *out = *iter->y;
    return true;
}
bool velIter_getID(velIter *iter, int *out) {
    if (!iter || iter->base.left == 0)
      return false;
    *out = *iter->base.cmp_id;
    return true;
}

//health

void hpIter_init(hpIter *iter) {
    if (!iter)
        return;
    iter->val = ph->hp;
    iter->base.cmp_id = ph->cmp_id;
    iter->base.left = ph->size;
}

bool hpIter_next(hpIter *iter) {
    if (!iter || iter->base.left == 0)
        return false;


    iter->val++;
    iter->base.cmp_id++;
    return --iter->base.left;
}

bool hpIter_getHP(hpIter *iter, double *out) {
    if (!iter || iter->base.left == 0)
        return false;
    *out = *iter->val;
    return true;
}

bool hpIter_getID(hpIter *iter, int *out) {
    if (!iter || iter->base.left == 0)
        return false;
    *out = *iter->base.cmp_id;
    return true;
}

// Attack

void attIter_init(attIter *iter) {
    if (!iter)
        return;
    iter->val = pa->dmg;
    iter->base.cmp_id = pa->cmp_id;
    iter->base.left = pa->size;
}
bool attIter_next(attIter *iter) {
    if (!iter || iter->base.left == 0)
        return false;
    iter->val++;
    iter->base.cmp_id++;
    return --iter->base.left;
}

bool attIter_getDmg(attIter *iter, double *out) {
    if (!iter || iter->base.left == 0)
        return false;
    *out = *iter->val;
    return true;
}

bool attIter_getID(attIter *iter, int *out) {
    if (!iter || iter->base.left == 0)
        return false;
    *out = *iter->base.cmp_id;
    return true;
}


//ASCII ART

void pasIter_init(pasIter *iter) {
    if (!iter)
        return;
    iter->val = pas->ascii;
    iter->base.cmp_id = pas->cmp_id;
    iter->base.left = pas->size;
}

bool pasIter_next(pasIter *iter) {
     if (!iter || iter->base.left == 0)
        return false;
    iter->val++;
    iter->base.cmp_id++;
    return --iter->base.left;
}
bool pasIter_getCh(pasIter *iter, char *out) {
    if (!iter || iter->base.left == 0)
        return false;
    *out = *iter->val;
    return true;
}

bool pasIter_getID(pasIter *iter, int *out) {
    if (!iter || iter->base.left == 0)
        return false;
    *out = *iter->base.cmp_id;
    return true;
}

// debug

void print_all_stores() {
    printf("Positions:\n");
    pp_print(pp);
    printf("Velocities:\n");
    pv_print(pv);
    printf("Healtsh:\n");
    ph_print(ph);
    printf("Attacks:\n");
    pa_print(pa);
    printf("ASCII:\n");
    pas_print(pas);
}
