#include <vector>

extern "C" {
bool* kidsWithCandies(
    int* candies, int candiesSize, int extraCandies, int* returnSize);
}

std::vector<bool> solution_c(std::vector<int> candies, int extraCandies) {
  int returnSize{};
  bool* returnData{kidsWithCandies(
      candies.data(), candies.size(), extraCandies, &returnSize)};

  std::vector<bool> output(returnSize);
  for (int i{0}; i < returnSize; ++i) output[i] = returnData[i];

  return output;
}
