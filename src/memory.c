#include "../include/memory.h"

bool pa_init(PackedArray* pa, int capacity) {
  if (!pa || capacity <= 0) {
    return false;
  }
  pa->data = (int*)malloc(sizeof(int) * capacity * POS_STRIDE);
  
  if(!pa->data) {
    return false;
  }
  
  pa->capacity = capacity;
  pa->size = 0;

  return true;
}

bool pa_push(PackedArray* pa, int x, int y) {
  if(!pa->data) {
    return false;
  }

  if(pa->size == pa->capacity) {
    return false;
  }

  pa->data[pa->size * POS_STRIDE] = x;
  pa->data[pa->size * POS_STRIDE + 1] = y;

  pa->size++;

  return true;

}

bool pa_remove(PackedArray* pa, int n) {
  if(!pa || !pa->data) {
    return false;
  }
  
  if (n >= pa->size) {
    return false;
  }

  int index = n * POS_STRIDE - POS_STRIDE;

  int tmp_x = pa->data[pa->size * POS_STRIDE - 1];
  int tmp_y = pa->data[pa->size * POS_STRIDE - 2];

  pa->data[pa->size * POS_STRIDE - 1] = pa->data[index];
  pa->data[pa->size * POS_STRIDE - 2] = pa->data[index + 1];
  
  pa->data[index] = tmp_x;
  pa->data[index + 1] = tmp_y;
  
  pa->size--;

  return true;
}

void pa_free(PackedArray* pa) {
  if (!pa) return;
  free(pa->data);
  pa->size = 0;
  pa->capacity = 0;
  pa->data = NULL;
}

void pa_print(PackedArray* pa, char* msg) {
  if(!pa) {
    printf("No position components");
    return;
  }
  int j = POS_STRIDE;
  for(int i = 0; i < pa->size; i++) {
    printf(msg, i, pa->data[j - POS_STRIDE], pa->data[j - 1]);
    j += POS_STRIDE;
  }
}
