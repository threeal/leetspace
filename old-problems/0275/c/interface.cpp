#include <vector>

extern "C" {
int hIndex(int* citations, int citationsSize);
}

int solution_c(std::vector<int> citations) {
  return hIndex(citations.data(), citations.size());
}
