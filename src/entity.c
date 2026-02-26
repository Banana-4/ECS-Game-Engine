#include "../include/entity.h"

static int freeIDsize = 0;
static int freeIds[MAX_ENTITIES];
static int nextID = 0;

int get_id() {
  if (freeIDsize > 0) {
    return freeIds[--freeIDsize];
  }
  if(nextID == MAX_ENTITIES - 1) return -1;
  return nextID++;
}

void recycle_id(int id) {
  freeIds[freeIDsize++] = id;
}

int enMod_dump() {
    const char buf[] = "data/buf_enmod.json";
    const char save[] = "data/entity_mod.json";
    char entity[100];
    FILE *fp = fopen(buf, "w");
    if (!fp) {
        perror("Failed to open buffer file");
        return 1;
    }

    fputs("{ \"name\" : \"entity_module\", \"recycled\" : [\n", fp);

    for (int i = 0; i < freeIDsize; i++) {
        fprintf(fp, "%d", freeIds[i]);
        if (i < freeIDsize - 2)
            fputs(", ", fp);
    }
    fputs("],\n", fp);
    fprintf(fp,"\"nextID\" : %d\n}", nextID);
    fflush(fp);
    fclose(fp);
    if (rename(buf, save) != 0) {
        perror("Error renaming file");
        return 2;
    }
    return 0;
}
