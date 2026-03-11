#include "../include/ecs.h"


int main() {
    static const size_t cap = 32;
    ecs_init(cap);

    // TEST ENTITY MANAGER

    int id = ecs_create_entity();
    printf("New ID: %d\n", id);
    if (!ecs_add_position(id, 0, 0))
        printf("Can't add position.\n");

    if (!ecs_add_velocity(id, 1, 1))
        printf("Can't add velocity\n");

    print_entites_store();

    printf("Test iterations and double adding of components.\n");
    for (int i = 0; i < 10; ++i) {
        ecs_create_entity();
    }
    enIter iter;
    if (!enIter_init(&iter))
        printf("Can't init iter.\n");
    while (enIter_valid(&iter)) {
        enIter_getID(&iter, &id);
        if (!ecs_add_position(id, 0, 0))
            printf("Can't add position.\n");
        if (!ecs_add_velocity(id, 1, 1))
            printf("Can't add velocity\n");
        enIter_next(&iter);
    }

    print_entites_store();

    printf("Testing: removal of entities while iterating.\n");
    if (!enIter_init(&iter))
        printf("Can't init iter.\n");
    while (enIter_valid(&iter)) {
        enIter_getID(&iter, &id);
        if (!ecs_remove_entity(id))
            printf("Can't remove entity: %d\n", id);
        printf("Removed Entity: %d\n", id);
        enIter_next(&iter);
    }

    print_entites_store();


    ecs_stop();
}
