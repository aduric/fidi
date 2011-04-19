/* Unit vector points int to I direction */

#define I 1
#define J 0
#define K 0

typedef struct vector {

  double x;
  double y;
  double z;

} Vector;

Vector rotate(Vector* u, double degrees);
