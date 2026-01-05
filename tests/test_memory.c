#include "../include/memory.h"


int main() {
  PackedArray* pa = (PackedArray*)malloc(sizeof(PackedArray));
  PackedArray* entities = (PackedArray*)malloc(sizeof(PackedArray));
  int capacity = 5;
  if (pa_init(pa, capacity)) {
    for(int i = 0; i < pa->capacity * POS_STRIDE; i += 2) {
      pa_push(pa, i, i + 1);
    }
    printf("Build array\n");
    pa_print(pa, "Index %d: X: %d, Y: %d \n");
    pa_remove(pa, 2);
    pa_remove(pa, 1);
    printf("After removal, size: %d\n", pa->size);
    pa_print(pa, "Index %d: X: %d, Y: %d \n");
    pa_free(pa);
    free(pa);
  }
  if(pa_init(entities, capacity)) {
    for(int i = 0; i < entities->capacity; i++) {
      pa_push(entities, i, 4);
      }
    pa_print(entities,"Entity: %d ID: %d, Mask: %d\n");
  }
}
