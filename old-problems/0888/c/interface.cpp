#include <cstring>
#include <vector>

extern "C" {
int* fairCandySwap(
    int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize,
    int* returnSize);
}

std::vector<int> solution_c(
    std::vector<int> aliceSizes, std::vector<int> bobSizes) {
  int returnSize{};
  const auto returnData = fairCandySwap(
      aliceSizes.data(), aliceSizes.size(), bobSizes.data(), bobSizes.size(),
      &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
