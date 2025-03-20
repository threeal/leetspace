#include <vector>

extern "C" {
int maximumCandies(int* candies, int candiesSize, long long k);
}

int solution_c(std::vector<int> candies, long long k) {
  return maximumCandies(candies.data(), candies.size(), k);
}
