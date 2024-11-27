#include <vector>

extern "C" {
int countUnguarded(
    int m, int n, int** guards, int guardsSize, int* guardsColSize,
    int** walls, int wallsSize, int* wallsColSize);
}

int solution_c(
    int m, int n, std::vector<std::vector<int>> guards,
    std::vector<std::vector<int>> walls) {
  std::vector<int*> guardsDatas(guards.size());
  std::vector<int> guardsSizes(guards.size());
  for (std::size_t i{0}; i < guards.size(); ++i) {
    guardsDatas[i] = guards[i].data();
    guardsSizes[i] = guards[i].size();
  }

  std::vector<int*> wallsDatas(walls.size());
  std::vector<int> wallsSizes(walls.size());
  for (std::size_t i{0}; i < walls.size(); ++i) {
    wallsDatas[i] = walls[i].data();
    wallsSizes[i] = walls[i].size();
  }

  return countUnguarded(
      m, n, guardsDatas.data(), guardsDatas.size(), guardsSizes.data(),
      wallsDatas.data(), wallsDatas.size(), wallsSizes.data());
}
