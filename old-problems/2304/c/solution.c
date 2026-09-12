int minPathCost(
    int** grid, int gridSize, int* gridColSize, int** moveCost,
    int moveCostSize, int* moveCostColSize) {
  return grid[gridSize - 1][gridColSize[gridSize - 1] - 1] +
      moveCost[moveCostSize - 1][moveCostColSize[moveCostSize - 1] - 1];
}
