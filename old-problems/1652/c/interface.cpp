#include <cstring>
#include <vector>

extern "C" {
int* decrypt(int* code, int codeSize, int k, int* returnSize);
}

std::vector<int> solution_c(std::vector<int> code, int k) {
  int returnSize{};
  const auto returnData = decrypt(code.data(), code.size(), k, &returnSize);

  std::vector<int> output(returnSize);
  std::memcpy(output.data(), returnData, returnSize * sizeof(int));

  return output;
}
