#include <vector>

extern "C" {
int latestDayToCross(
    int row, int col, int** cells, int cellsSize, int* cellsColSize);
}

int solution_c(int row, int col, std::vector<std::vector<int>> cells) {
  std::vector<int*> cellsDatas(cells.size());
  std::vector<int> cellsSizes(cells.size());
  for (std::size_t i{0}; i < cells.size(); ++i) {
    cellsDatas[i] = cells[i].data();
    cellsSizes[i] = cells[i].size();
  }

  return latestDayToCross(
      row, col, cellsDatas.data(), cells.size(), cellsSizes.data());
}
