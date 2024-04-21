int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
  int perimeter = 0;

  if (grid[0][0] == 1) {
    perimeter += 4;
  }

  for (int j = 1; j < gridColSize[0]; ++j) {
    if (grid[0][j] == 1) {
      perimeter += grid[0][j - 1] == 0 ? 4 : 2;
    }
  }

  for (int i = 1; i < gridSize; ++i) {
    if (grid[i][0] == 1) {
      perimeter += grid[i - 1][0] == 0 ? 4 : 2;
    }

    for (int j = 1; j < gridColSize[i]; ++j) {
      if (grid[i][j] == 1) {
        if (grid[i - 1][j] == 0) {
          if (grid[i][j - 1] == 0) {
            perimeter += 4;
          } else {
            perimeter += 2;
          }
        } else if (grid[i][j - 1] == 0) {
          perimeter += 2;
        }
      }
    }
  }

  return perimeter;
}
