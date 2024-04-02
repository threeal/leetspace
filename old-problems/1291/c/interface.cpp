#include <cstring>
#include <vector>

extern "C" {
int* sequentialDigits(int low, int high, int* returnSize);
}

std::vector<int> solution_c(int low, int high) {
  int returnSize;
  const auto returnData = sequentialDigits(low, high, &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
