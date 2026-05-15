int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
  int count = 0;
  if (grid[0][0] <= k) ++count;

  for (int i = 1; i < gridColSize[0]; ++i) {
    grid[0][i] += grid[0][i - 1];
    if (grid[0][i] <= k) {
      ++count;
    } else {
      break;
    }
  }

  for (int i = 1; i < gridSize; ++i) {
    grid[i][0] += grid[i - 1][0];
    if (grid[i][0] <= k) {
      ++count;
      for (int j = 1; j < gridColSize[i]; ++j) {
        grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
        if (grid[i][j] <= k) {
          ++count;
        } else {
          break;
        }
      }
    } else {
      break;
    }
  }

  return count;
}
