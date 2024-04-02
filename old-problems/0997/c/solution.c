#include <stdbool.h>
#include <stdlib.h>

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
  (void)trustColSize;

  int* trustCount = malloc(n * sizeof(int));
  bool* trustAnyone = malloc(n * sizeof(bool));

  for (int i = 0; i < n; ++i) {
    trustCount[i] = 0;
    trustAnyone[i] = false;
  }

  for (int i = 0; i < trustSize; ++i) {
    trustAnyone[trust[i][0] - 1] = true;
    ++trustCount[trust[i][1] - 1];
  }

  for (int i = 0; i < n; ++i) {
    if (trustCount[i] == n - 1 && !trustAnyone[i]) {
      return i + 1;
    }
  }

  return -1;
}
