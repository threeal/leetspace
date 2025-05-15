#include <cstring>
#include <vector>

extern "C" {
int* stableMountains(
    int* height, int heightSize, int threshold, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> height, int threshold) {
  int returnSize{};
  int* returnData{
      stableMountains(height.data(), height.size(), threshold, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
