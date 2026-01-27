#include "../include/component.h"
#include <stdlib.h>

PackedPositions* pp; 
PackedHealths* ph;
PackedVelocities* pv;
PackedAttacks *pa;
PackedASCII* pas;




bool init_stores(int capacity) {
  if (!pp_init(pp, capacity)) {
    return false;
  }
  if(!ph_init(ph, capacity)) {
    pp_free(pp);
    return false;
  }
  if (!pv_init(pv, capacity)) {
    pp_free(pp);
    ph_free(ph);
    return false;
  }
  if (!pas_init(pas, capacity)) {
    pp_free(pp);
    ph_free(ph);
    pv_free(pv);
    return false;
  }
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

bool position_insert(int id, int x, int y) {
   return pp_insert(pp, id, x, y);
}

bool velocity_insert(int id, int x, int y) {
    return pv_insert(pv, id, x, y);
}
bool health_insert(int id, double hp) {
     return ph_insert(ph, id, hp);
}

bool ascii_insert(int id, char ch){
    return pas_insert(pas, id, ch);
}
bool attack_insert(int id, double dmg) {
    return pa_insert(pa, id, dmg);
}


void get_postion(int id, ppData* out) {
    out->x = pp->x[pp->id_map[id]];
    out->y = pp->y[pp->id_map[id]];
}
void get_velocity(int id, pvData* out) {
    out->x = pv->x[pv->id_map[id]];
    out->y = pv->y[pv->id_map[id]];
}

void get_health(int id, phData* out) {
  out->hp = ph->hp[ph->id_map[id]];
}

void get_attack(int id, paData* out) {
  out->dmg = pa->dmg[pa->id_map[id]];
}

void get_ascii(int id, pasData* out) {
  out->ascii = pas->ascii[pas->id_map[id]];
}
