#include <stdlib.h>
#include <string.h>

int maxMoves(int** grid, int gridSize, int* gridColSize) {
  int* moves = malloc(gridSize * sizeof(int));
  memset(moves, 0, gridSize * sizeof(int));

  int* nextMoves = malloc(gridSize * sizeof(int));

  for (int i = gridColSize[gridSize - 1] - 2; i >= 0; --i) {
    int* temp = moves;
    moves = nextMoves;
    nextMoves = temp;

    int j = gridSize - 1;
    moves[j] = 0;
    if (grid[j][i] < grid[j - 1][i + 1] && moves[j] < 1 + nextMoves[j - 1]) {
      moves[j] = 1 + nextMoves[j - 1];
    }
    if (grid[j][i] < grid[j][i + 1] && moves[j] < 1 + nextMoves[j]) {
      moves[j] = 1 + nextMoves[j];
    }

    for (--j; j > 0; --j) {
      moves[j] = 0;
      if (grid[j][i] < grid[j - 1][i + 1] && moves[j] < 1 + nextMoves[j - 1]) {
        moves[j] = 1 + nextMoves[j - 1];
      }
      if (grid[j][i] < grid[j][i + 1] && moves[j] < 1 + nextMoves[j]) {
        moves[j] = 1 + nextMoves[j];
      }
      if (grid[j][i] < grid[j + 1][i + 1] && moves[j] < 1 + nextMoves[j + 1]) {
        moves[j] = 1 + nextMoves[j + 1];
      }
    }

    moves[0] = 0;
    if (grid[0][i] < grid[0][i + 1] && moves[0] < 1 + nextMoves[0]) {
      moves[0] = 1 + nextMoves[0];
    }
    if (grid[0][i] < grid[1][i + 1] && moves[0] < 1 + nextMoves[1]) {
      moves[0] = 1 + nextMoves[1];
    }
  }

  int max = moves[0];
  for (int i = 1; i < gridSize; ++i) {
    if (moves[i] > max) max = moves[i];
  }

  return max;
}
