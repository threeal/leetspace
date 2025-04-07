#include <cstring>
#include <vector>

extern "C" {
int* countBits(int n, int* returnSize);
}

std::vector<int> solution_c(int n) {
  int returnSize{};
  const int* returnData{countBits(n, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
