#include <vector>

extern "C" {
int countSubIslands(
    int** grid1, int grid1Size, int* grid1ColSize,
    int** grid2, int grid2Size, int* grid2ColSize);
}

int solution_c(
    std::vector<std::vector<int>> grid1, std::vector<std::vector<int>> grid2) {
  std::vector<int*> grid1Datas(grid1.size());
  std::vector<int> grid1Sizes(grid2.size());
  for (int i = grid1.size() - 1; i >= 0; --i) {
    grid1Datas[i] = grid1[i].data();
    grid1Sizes[i] = grid1[i].size();
  }

  std::vector<int*> grid2Datas(grid2.size());
  std::vector<int> grid2Sizes(grid2.size());
  for (int i = grid2.size() - 1; i >= 0; --i) {
    grid2Datas[i] = grid2[i].data();
    grid2Sizes[i] = grid2[i].size();
  }

  return countSubIslands(
      grid1Datas.data(), grid1Datas.size(), grid1Sizes.data(),
      grid2Datas.data(), grid2Datas.size(), grid2Sizes.data());
}
