#include "../include/component.h"
#include <stdio.h>

int main() {
    int cap = 32;
    init_stores(cap);
    print_all_stores();
    for (int i = 0; i < cap; i++) {
        if (!position_insert(i, i + 2, i - 1)) {
            printf("Error while adding new position comp.\n");
        }
        if (!velocity_insert(i, i + 2, i - 1)) {
            printf("Error while adding new velocity comp.\n");
        }
        if (!health_insert(i, i * 100.0)) {
            printf("Error while adding new health comp.\n");
        }
        if (!attack_insert(i, i * 10.0)) {
            printf("Error while adding new attack comp.\n");
        }
        if (!ascii_insert(i, i % 200 + 40)) {
            printf("Error while adding new ascii comp.\n");
        }
    }
    print_all_stores();
    posIter iter;
    posIter_init(&iter);
    printf("Nacked iter x: %d\n", *(iter.x + 2));

    int x;
    int y;
    int id;
    while (iter_valid(iter.base)) {
        posIter_getX(&iter, &x);
        posIter_getY(&iter,&y);
        posIter_getID(&iter, &id);
        printf("X: %d, Y: %d, ID: %d\n",x,y,id);
        posIter_next(&iter);
    }

    printf("Access to used up iter: %d\n", *(iter.x));
    printf("Testing uninitilazed iter.\n");
    posIter iter_bad;
    while (iter_valid(iter_bad.base)) {
        posIter_getX(&iter_bad, &x);
        posIter_getY(&iter_bad,&y);
        posIter_getID(&iter_bad, &id);
        printf("X: %d, Y: %d, ID: %d\n",x,y,id);
        posIter_next(&iter_bad);
    }

}
