#include <cstring>
#include <vector>

extern "C" {
int* replaceElements(int* arr, int arrSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> arr) {
  int returnSize;
  const auto returnData = replaceElements(arr.data(), arr.size(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
