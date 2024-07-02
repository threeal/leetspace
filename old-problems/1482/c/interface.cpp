#include <vector>

extern "C" {
int minDays(int* bloomDay, int bloomDaySize, int m, int k);
}

int solution_c(std::vector<int> bloomDay, int m, int k) {
  return minDays(bloomDay.data(), bloomDay.size(), m, k);
}
