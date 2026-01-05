#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define POS_STRIDE 2

//stores data that contains two ints
typedef struct {
  int* data;
  int capacity;
  int size;
} PackedArray;

bool pa_init(PackedArray* pa, int capacity);
bool pa_push(PackedArray* pa, int x, int y);
bool pa_remove(PackedArray* pa, int n);
void pa_free(PackedArray* pa);
void pa_print(PackedArray* pa, char* msg);




