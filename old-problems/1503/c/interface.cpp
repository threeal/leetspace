#include <vector>

extern "C" {
int getLastMoment(int n, int* left, int leftSize, int* right, int rightSize);
}

int solution_c(int n, std::vector<int> left, std::vector<int> right) {
  return getLastMoment(n, left.data(), left.size(), right.data(), right.size());
}
