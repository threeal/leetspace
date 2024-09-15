#include <cstring>
#include <vector>

extern "C" {
int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> rolls, int mean, int n) {
  int returnSize;
  const auto returnData = missingRolls(
      rolls.data(), rolls.size(), mean, n, &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
