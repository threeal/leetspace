#include <cstring>
#include <vector>

extern "C" {
int* getRow(int rowIndex, int* returnSize);
}

std::vector<int> solution_c(int rowIndex) {
  int returnSize{};
  auto returnData = getRow(rowIndex, &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
