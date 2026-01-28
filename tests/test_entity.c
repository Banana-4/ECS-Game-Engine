#include "../include/entity.h"
//bug in removing needs urgent fixing
int main() {
    int cap = 32;
    if (!init_entities(cap)) {
        printf("Faild to create Entities store for %d\n", cap);
    }
    int id = create_entity(1|2|4);
    printf("ID: %d\n", id);
    if(!remove_entity(id)) {
        printf("Faild to remove id: %d\n", id);
    }

    for(int i = 0; i < cap; ++i) {
        create_entity(1|2|4);
    }

    print_entites_store();

    EnIter* iter = create_enIter();
    int count = 0;
    while(true) {
        count++;
        remove_entity(id_enIter(iter));
        if (!next_enIter(iter)) {
            break;
        }
    }
    printf("Total ids removed: %d\n", count);
    printf("After clearing the store.\n");
    print_entites_store();
    return 0;
}
