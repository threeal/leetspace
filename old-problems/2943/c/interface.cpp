#include <vector>

extern "C" {
int maximizeSquareHoleArea(
    int n, int m, int* hBars, int hBarsSize, int* vBars, int vBarsSize);
}

int solution_c(int n, int m, std::vector<int> hBars, std::vector<int> vBars) {
  return maximizeSquareHoleArea(
      n, m, hBars.data(), hBars.size(), vBars.data(), vBars.size());
}
