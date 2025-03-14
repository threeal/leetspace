#include <cstring>
#include <vector>

extern "C" {
int* closestPrimes(int left, int right, int* returnSize);
}

std::vector<int> solution_c(int left, int right) {
  int returnSize{};
  int* returnData = closestPrimes(left, right, &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
