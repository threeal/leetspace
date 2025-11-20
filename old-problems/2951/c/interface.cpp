#include <cstring>
#include <vector>

extern "C" {
int* findPeaks(int* mountain, int mountainSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> mountain) {
  int returnSize{};
  int* returnData{findPeaks(mountain.data(), mountain.size(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
