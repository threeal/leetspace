#include <cstring>
#include <vector>

extern "C" {
int* findThePrefixCommonArray(
    int* A, int ASize, int* B, int BSize, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> A, std::vector<int> B) {
  int returnSize{};
  int* returnData = findThePrefixCommonArray(
      A.data(), A.size(), B.data(), B.size(), &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
