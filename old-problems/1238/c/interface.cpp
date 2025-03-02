#include <cstring>
#include <vector>

extern "C" {
int* circularPermutation(int n, int start, int* returnSize);
}

std::vector<int> solution_c(int n, int start) {
  int returnSize{};
  int* returnData = circularPermutation(n, start, &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
