#include <vector>

extern "C" {
int maxCount(int* banned, int bannedSize, int n, int maxSum);
}

int solution_c(std::vector<int> banned, int n, int maxSum) {
  return maxCount(banned.data(), banned.size(), n, maxSum);
}
