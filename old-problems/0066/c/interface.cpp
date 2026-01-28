#include <cstring>
#include <vector>

extern "C" {
int* plusOne(int* digits, int digitsSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> digits) {
  int returnSize{};
  int* returnData{plusOne(digits.data(), digits.size(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
