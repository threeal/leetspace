#include <math.h>

int maximumGroups(int* grades, int gradesSize) {
  (void)grades;
  return sqrt(gradesSize * 2 + 0.25) - 0.5;
}
