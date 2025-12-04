#include <cstring>
#include <vector>

extern "C" {
int* evenOddBit(int n, int* returnSize);
}

std::vector<int> solution_c(int n) {
  int returnSize{};
  int* returnData{evenOddBit(n, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
