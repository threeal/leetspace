#include <vector>

extern "C" {
int countCompleteDayPairs(int* hours, int hoursSize);
}

int solution_c(std::vector<int> hours) {
  return countCompleteDayPairs(hours.data(), hours.size());
}
