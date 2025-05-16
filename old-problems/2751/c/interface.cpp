#include <cstring>
#include <string>
#include <vector>

extern "C" {
int* survivedRobotsHealths(
    int* positions, int positionsSize,
    int* healths, int healthsSize,
    char* directions, int* returnSize);
}

std::vector<int> solution_c(
    std::vector<int> positions,
    std::vector<int> healths,
    std::string directions) {
  int returnSize{};
  const auto returnData = survivedRobotsHealths(
      positions.data(), positions.size(),
      healths.data(), healths.size(),
      directions.data(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
