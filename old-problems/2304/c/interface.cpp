#include <vector>

extern "C" {
int minPathCost(
    int** grid, int gridSize, int* gridColSize, int** moveCost,
    int moveCostSize, int* moveCostColSize);
}

int solution_c(
    std::vector<std::vector<int>> grid,
    std::vector<std::vector<int>> moveCost) {
  std::vector<int*> gridDatas(grid.size());
  std::vector<int> gridSizes(grid.size());
  for (std::size_t i{0}; i < grid.size(); ++i) {
    gridDatas[i] = grid[i].data();
    gridSizes[i] = grid[i].size();
  }

  std::vector<int*> moveCostDatas(moveCost.size());
  std::vector<int> moveCostSizes(moveCost.size());
  for (std::size_t i{0}; i < moveCost.size(); ++i) {
    moveCostDatas[i] = moveCost[i].data();
    moveCostSizes[i] = moveCost[i].size();
  }

  return minPathCost(
      gridDatas.data(), grid.size(), gridSizes.data(), moveCostDatas.data(),
      moveCost.size(), moveCostSizes.data());
}
