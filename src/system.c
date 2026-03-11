#include "../include/system.h"
#ifndef ENTITY_H
#define ENTITY_H
#include "../include/entity.h"
#endif
#ifndef COMPONENT_H
#define COMPONENT_H
#include "../include/component.h"
#endif
#ifndef ECS_H
#define ECS_H
#include "../include/ecs.h"
#endif

#include <stdio.h>

int pos_dump() {
    const char buf_file[] = "data/pos_buf.json";
    const char store_name[] = "data/positions.json";
    char component[100];
    FILE *fp = fopen(buf_file, "w");
    if (!fp) {
    perror("Failed to open buffer file");
    return 1;
    }
    posIter iter;
    posIter_init(&iter);
    if (!iter_valid(iter.base)) {
      return -1;
    }
    fputs("{ \"name\" : \"positions\", \"components\" : [\n", fp);
    while(1) {
        int id;
        int x;
        int y;
        posIter_getID(&iter, &id);
        posIter_getX(&iter, &x);
        posIter_getY(&iter, &y);
        sprintf(component, "{ \"id\" : %d, \"x\" : %d, \"y\" : %d }", id, x, y);
        fputs(component, fp);
        posIter_next(&iter);
        if (iter_valid(iter.base)) {
            fputs(",\n", fp);
        } else {
            break;
        }
    }
    fputs(" ] }", fp);
    fflush(fp);
    fclose(fp);
    if (rename(buf_file, store_name) != 0) {
        perror("Error renaming file");
        return 2;
    }
    return 0;
}


int vel_dump() {
    const char buf_file[] = "data/vel_buf.json";
    const char store_name[] = "data/velocities.json";
    char component[100];
    FILE *fp = fopen(buf_file, "w");
    if (!fp) {
    perror("Failed to open buffer file");
    return 1;
    }
    velIter iter;
    velIter_init(&iter);
    if (!iter_valid(iter.base)) {
      return -1;
    }
    fputs("{ \"name\" : \"velocities\", \"components\" : [\n", fp);
    while(1) {
        int id;
        int x;
        int y;
        velIter_getID(&iter, &id);
        velIter_getX(&iter, &x);
        velIter_getY(&iter, &y);
        sprintf(component, "{ \"id\" : %d, \"x\" : %d, \"y\" : %d }", id, x, y);
        fputs(component, fp);
        velIter_next(&iter);
        if (iter_valid(iter.base)) {
            fputs(",\n", fp);
        } else {
            break;
        }
    }
    fputs(" ] }", fp);
    fflush(fp);
    fclose(fp);
    if (rename(buf_file, store_name) != 0) {
        perror("Error renaming file");
        return 2;
    }
    return 0;
}


int hp_dump() {
    const char buf_file[] = "data/hp_buf.json";
    const char store_name[] = "data/healths.json";
    char component[100];
    FILE *fp = fopen(buf_file, "w");
    if (!fp) {
    perror("Failed to open buffer file");
    return 1;
    }
    hpIter iter;
    hpIter_init(&iter);
    if (!iter_valid(iter.base)) {
      return -1;
    }
    fputs("{ \"name\" : \"healths\", \"components\" : [\n", fp);
    while(1) {
        int id;
        double hp;
        hpIter_getID(&iter, &id);
        hpIter_getHP(&iter, &hp);
        sprintf(component, "{ \"id\" : %d, \"hp\" : %lf }", id, hp);
        fputs(component, fp);
        hpIter_next(&iter);
        if (iter_valid(iter.base)) {
            fputs(",\n", fp);
        } else {
            break;
        }
    }
    fputs(" ] }", fp);
    fflush(fp);
    fclose(fp);
    if (rename(buf_file, store_name) != 0) {
        perror("Error renaming file");
        return 2;
    }
    return 0;
}

int att_dump() {
    const char buf_file[] = "data/att_buf.json";
    const char store_name[] = "data/attacks.json";
    char component[100];
    FILE *fp = fopen(buf_file, "w");
    if (!fp) {
    perror("Failed to open buffer file");
    return 1;
    }
    attIter iter;
    attIter_init(&iter);
    if (!iter_valid(iter.base)) {
      return -1;
    }
    fputs("{ \"name\" : \"attacks\", \"components\" : [\n", fp);
    while(1) {
        int id;
        double dmg;
        attIter_getID(&iter, &id);
        attIter_getDmg(&iter, &dmg);
        sprintf(component, "{ \"id\" : %d, \"dmg\" : %lf }", id, dmg);
        fputs(component, fp);
        attIter_next(&iter);
        if (iter_valid(iter.base)) {
            fputs(",\n", fp);
        } else {
            break;
        }
    }
    fputs(" ] }", fp);
    fflush(fp);
    fclose(fp);
    if (rename(buf_file, store_name) != 0) {
        perror("Error renaming file");
        return 2;
    }
    return 0;
}

int ascii_dump() {
    const char buf_file[] = "data/ascii_buf.json";
    const char store_name[] = "data/asciis.json";
    char component[100];
    FILE *fp = fopen(buf_file, "w");
    if (!fp) {
    perror("Failed to open buffer file");
    return 1;
    }
    pasIter iter;
    pasIter_init(&iter);
    if (!iter_valid(iter.base)) {
      return -1;
    }
    fputs("{ \"name\" : \"ASCII\", \"components\" : [\n", fp);
    while(1) {
        int id;
        char c;
        pasIter_getID(&iter, &id);
        pasIter_getCh(&iter, &c);
        sprintf(component, "{ \"id\" : %d, \"ascii\" : %c }", id, c);
        fputs(component, fp);
        pasIter_next(&iter);
        if (iter_valid(iter.base)) {
            fputs(",\n", fp);
        } else {
            break;
        }
    }
    fputs(" ] }", fp);
    fflush(fp);
    fclose(fp);
    if (rename(buf_file, store_name) != 0) {
        perror("Error renaming file");
        return 2;
    }
    return 0;
}

int en_dump() {
    const char buf[] = "data/buf_en.json";
    const char save[] = "data/entities.json";
    char entity[100];
    FILE *fp = fopen(buf, "w");
    if (!fp) {
        perror("Failed to open buffer file");
        return 1;
    }
    enIter iter;
    if (!enIter_init(&iter)) {
        return -1;
    }

    fputs("{ \"name\" : \"entity\", \"entities\" : [\n", fp);
    while (1) {
        int id;
        unsigned mask;
        enIter_getID(&iter, &id);
        enIter_getMask(&iter, &mask);
        sprintf(entity, "{ \"id\" : %d, \"mask\" : %u }", id, mask);
        fputs(entity, fp);
        if (enIter_next(&iter)) {
            fputs(",\n", fp);
        } else {
            break;
        }
    }
    fputs("] }", fp);
    fflush(fp);
    fclose(fp);

    if (rename(buf, save) != 0) {
        perror("Error renaming file");
        return 2;
    }
    return 0;
}
