#include <cstring>
#include <vector>

extern "C" {
int* minCosts(int* cost, int costSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> cost) {
  int returnSize{};
  int* returnData{minCosts(cost.data(), cost.size(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
