#include <stdbool.h>

bool mergeTriplets(
    int** triplets, int tripletsSize, int* tripletsColSize,
    int* target, int targetSize) {
  (void)tripletsColSize;
  (void)targetSize;
  int flag = 0;
  for (int i = 0; i < tripletsSize; ++i) {
    if (triplets[i][0] <= target[0] && triplets[i][1] <= target[1] &&
        triplets[i][2] <= target[2]) {
      if (triplets[i][0] == target[0]) flag |= 1;
      if (triplets[i][1] == target[1]) flag |= 2;
      if (triplets[i][2] == target[2]) flag |= 4;
      if (flag == 7) return true;
    }
  }
  return false;
}
