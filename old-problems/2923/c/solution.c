int findChampion(int** grid, int gridSize, int* gridColSize) {
  for (int j = 0; j < gridColSize[0]; ++j) {
    int i = 0;
    while (i < gridSize) {
      if (grid[i][j] == 1) break;
      ++i;
    }
    if (i == gridSize) return j;
  }
  return 0;
}
