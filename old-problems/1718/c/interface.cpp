#include <cstring>
#include <vector>

extern "C" {
int* constructDistancedSequence(int n, int* returnSize);
}

std::vector<int> solution_c(int n) {
  int returnSize{};
  int* returnData = constructDistancedSequence(n, &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
