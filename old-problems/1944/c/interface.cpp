#include <cstring>
#include <vector>

extern "C" {
int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> heights) {
  int returnSize{};
  int* returnData = canSeePersonsCount(heights.data(), heights.size(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
