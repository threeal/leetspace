#include <cstring>
#include <vector>

extern "C" {
int* decode(int* encoded, int encodedSize, int first, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> encoded, int first) {
  int returnSize{};
  int* returnData{decode(encoded.data(), encoded.size(), first, &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
