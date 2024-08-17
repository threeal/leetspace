#include <string>
#include <vector>

extern "C" {
int regionsBySlashes(char** grid, int gridSize);
}

int solution_c(std::vector<std::string> grid) {
  std::vector<char*> gridDatas(grid.size());
  for (int i = grid.size() - 1; i >= 0; --i) {
    gridDatas[i] = grid[i].data();
  }

  return regionsBySlashes(gridDatas.data(), gridDatas.size());
}
