#include <stdlib.h>

int** intervalIntersection(
    int** firstList, int firstListSize, int* firstListColSize,
    int** secondList, int secondListSize, int* secondListColSize,
    int* returnSize, int** returnColumnSizes) {
  (void)firstListColSize;
  (void)secondListColSize;

  int** intersections = malloc((firstListSize + secondListSize) * sizeof(int*));
  int* intersectionsColSize = malloc(
      (firstListSize + secondListSize) * sizeof(int));

  int intersectionsSize = 0;

  int fi = 0, si = 0;
  while (fi < firstListSize && si < secondListSize) {
    const int fl = firstList[fi][0], fr = firstList[fi][1];
    const int sl = secondList[si][0], sr = secondList[si][1];

    if (fl <= sl) {
      if (sl <= fr) {
        if (sr <= fr) {
          int* intersection = malloc(2 * sizeof(int));
          intersection[0] = sl;
          intersection[1] = sr;

          intersections[intersectionsSize] = intersection;
          intersectionsColSize[intersectionsSize++] = 2;

          firstList[fi][0] = sr;
          ++si;
        } else {
          int* intersection = malloc(2 * sizeof(int));
          intersection[0] = sl;
          intersection[1] = fr;

          intersections[intersectionsSize] = intersection;
          intersectionsColSize[intersectionsSize++] = 2;

          secondList[si][0] = fr;
          ++fi;
        }
      } else {
        ++fi;
      }
    } else {
      if (fl <= sr) {
        if (fr <= sr) {
          int* intersection = malloc(2 * sizeof(int));
          intersection[0] = fl;
          intersection[1] = fr;

          intersections[intersectionsSize] = intersection;
          intersectionsColSize[intersectionsSize++] = 2;

          secondList[si][0] = fr;
          ++fi;
        } else {
          int* intersection = malloc(2 * sizeof(int));
          intersection[0] = fl;
          intersection[1] = sr;

          intersections[intersectionsSize] = intersection;
          intersectionsColSize[intersectionsSize++] = 2;

          firstList[fi][0] = sr;
          ++si;
        }
      } else {
        ++si;
      }
    }
  }

  *returnSize = intersectionsSize;
  *returnColumnSizes = intersectionsColSize;
  return intersections;
}
