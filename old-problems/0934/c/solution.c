#include <stdlib.h>

int shortestBridge(int** grid, int gridSize, int* gridColSize) {
  (void)gridColSize;

  for (int i = gridSize - 1; i >= 0; --i) {
    for (int j = gridSize - 1; j >= 0; --j) {
      if (grid[i][j] == 0) continue;

      int* lands = malloc(gridSize * gridSize * sizeof(int));
      int* landsBegin = lands;
      int* landsEnd = lands;

      int* seas = malloc(gridSize * gridSize * sizeof(int));
      int* seasBegin = seas;
      int* seasEnd = seas;

      // Explore the first island and find the neighboring seas.
      grid[i][j] = 2;
      *landsEnd = i << 7 | j;
      ++landsEnd;
      while (landsBegin < landsEnd) {
        const int i = *landsBegin >> 7;
        const int j = *landsBegin & 127;

        if (i > 0 && grid[i - 1][j] >= 0) {
          if (grid[i - 1][j] == 0) {
            *seasEnd = (i - 1) << 7 | j;
            ++seasEnd;
          } else {
            *landsEnd = (i - 1) << 7 | j;
            ++landsEnd;
          }
          grid[i - 1][j] = -1;
        }

        if (j > 0 && grid[i][j - 1] >= 0) {
          if (grid[i][j - 1] == 0) {
            *seasEnd = i << 7 | (j - 1);
            ++seasEnd;
          } else {
            *landsEnd = i << 7 | (j - 1);
            ++landsEnd;
          }
          grid[i][j - 1] = -1;
        }

        if (i + 1 < gridSize && grid[i + 1][j] >= 0) {
          if (grid[i + 1][j] == 0) {
            *seasEnd = (i + 1) << 7 | j;
            ++seasEnd;
          } else {
            *landsEnd = (i + 1) << 7 | j;
            ++landsEnd;
          }
          grid[i + 1][j] = -1;
        }

        if (j + 1 < gridSize && grid[i][j + 1] >= 0) {
          if (grid[i][j + 1] == 0) {
            *seasEnd = i << 7 | (j + 1);
            ++seasEnd;
          } else {
            *landsEnd = i << 7 | (j + 1);
            ++landsEnd;
          }
          grid[i][j + 1] = -1;
        }

        ++landsBegin;
      }

      // Explore the sea until it reaches the next island.
      for (int distance = 1; seasBegin < seasEnd; ++distance) {
        const int* prevSeasEnd = seasEnd;
        while (seasBegin < prevSeasEnd) {
          const int i = *seasBegin >> 7;
          const int j = *seasBegin & 127;

          if (i > 0 && grid[i - 1][j] >= 0) {
            if (grid[i - 1][j] == 1) {
              free(lands);
              free(seas);
              return distance;
            }
            *seasEnd = (i - 1) << 7 | j;
            ++seasEnd;
            grid[i - 1][j] = -1;
          }

          if (j > 0 && grid[i][j - 1] >= 0) {
            if (grid[i][j - 1] == 1) {
              free(lands);
              free(seas);
              return distance;
            }
            *seasEnd = i << 7 | (j - 1);
            ++seasEnd;
            grid[i][j - 1] = -1;
          }

          if (i + 1 < gridSize && grid[i + 1][j] >= 0) {
            if (grid[i + 1][j] == 1) {
              free(lands);
              free(seas);
              return distance;
            }
            *seasEnd = (i + 1) << 7 | j;
            ++seasEnd;
            grid[i + 1][j] = -1;
          }

          if (j + 1 < gridSize && grid[i][j + 1] >= 0) {
            if (grid[i][j + 1] == 1) {
              free(lands);
              free(seas);
              return distance;
            }
            *seasEnd = i << 7 | (j + 1);
            ++seasEnd;
            grid[i][j + 1] = -1;
          }

          ++seasBegin;
        }
      }

      free(lands);
      free(seas);

      return 0;
    }
  }
  return 0;
}
