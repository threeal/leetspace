#include <cstring>
#include <string>
#include <vector>

extern "C" {
int* maxDepthAfterSplit(char* seq, int* returnSize);
}

std::vector<int> solution_c(std::string seq) {
  int returnSize{};
  const int* returnData{maxDepthAfterSplit(seq.data(), &returnSize)};

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
