typedef enum {
  position = 1,
  velocity = 2,
  health = 4,
  attack = 8,
}ComponentsID;

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
  int x;
  int y;
} Velocity;

typedef struct {
  double health;
} Health;

typedef struct {
  double dmg;
  int range;
} Attack;

