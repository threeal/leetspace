int uniquePathsWithObstacles(
    int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
  if (obstacleGrid[0][0] != 0) return 0;
  obstacleGrid[0][0] = 1;

  for (int j = 1; j < obstacleGridColSize[0]; ++j) {
    if (obstacleGrid[0][j] == 0) {
      obstacleGrid[0][j] = obstacleGrid[0][j - 1];
    } else {
      obstacleGrid[0][j] = 0;
    }
  }

  for (int i = 1; i < obstacleGridSize; ++i) {
    if (obstacleGrid[i][0] == 0) {
      obstacleGrid[i][0] = obstacleGrid[i - 1][0];
    } else {
      obstacleGrid[i][0] = 0;
    }

    for (int j = 1; j < obstacleGridColSize[i]; ++j) {
      if (obstacleGrid[i][j] == 0) {
        obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
      } else {
        obstacleGrid[i][j] = 0;
      }
    }
  }

  return obstacleGrid[obstacleGridSize - 1][obstacleGridColSize[obstacleGridSize - 1] - 1];
}
