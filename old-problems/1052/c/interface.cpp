#include <vector>

extern "C" {
int maxSatisfied(
    int* customers, int customersSize,
    int* grumpy, int grumpySize, int minutes);
}

int solution_c(
    std::vector<int> customers, std::vector<int> grumpy, int minutes) {
  return maxSatisfied(
      customers.data(), customers.size(),
      grumpy.data(), grumpy.size(), minutes);
}
