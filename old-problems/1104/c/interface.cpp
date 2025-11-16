#include <cstring>
#include <vector>

extern "C" {
int* pathInZigZagTree(int label, int* returnSize);
}

std::vector<int> solution_c(int label) {
  int returnSize{};
  int* returnData{pathInZigZagTree(label, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
