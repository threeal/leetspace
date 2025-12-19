#include <stdlib.h>

int* findBall(int** grid, int gridSize, int* gridColSize, int* returnSize) {
  const int ballsSize = gridColSize[0];
  int* balls = malloc(ballsSize * sizeof(int));
  for (int i = 0; i < ballsSize; ++i) balls[i] = i;

  for (int i = 0; i < gridSize; ++i) {
    for (int j = 0; j < ballsSize; ++j) {
      if (balls[j] >= 0) {
        if (grid[i][balls[j]] == 1) {
          if (balls[j] + 1 < ballsSize && grid[i][balls[j] + 1] == 1) {
            ++balls[j];
          } else {
            balls[j] = -1;
          }
        } else {
          if (balls[j] > 0 && grid[i][balls[j] - 1] != 1) {
            --balls[j];
          } else {
            balls[j] = -1;
          }
        }
      }
    }
  }

  *returnSize = ballsSize;
  return balls;
}
