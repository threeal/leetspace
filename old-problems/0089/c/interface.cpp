#include <cstring>
#include <vector>

extern "C" {
int* grayCode(int n, int* returnSize);
}

std::vector<int> solution_c(int n) {
  int returnSize{};
  int* returnData{grayCode(n, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
